#include "configparser.h"


ConfigParser::ConfigParser(CoreEngine *parent) :
    QObject(parent)
{
    this->core = parent;
    this->config_dir = new QDir("");
    this->config_base_dir = new QDir("");
    this->file_list = new QFileInfoList();
    this->machine_cfg_state = false;
    this->object_cfg_state = false;
    this->module_cfg_state = false;
    }

void ConfigParser::initConfigPath(const QString path)
    {
    this->config_dir->cd(path);
    this->config_base_dir->cd(path);
    if(!this->config_dir->entryList(QDir::AllDirs).contains(DEFAULT_CFG_DIR))
		{
		QDirIterator it(*this->config_dir, QDirIterator::Subdirectories);
		while (it.hasNext())
			{
			it.next();
			if(it.filePath().endsWith(DEFAULT_CFG_DIR))
				{
				this->config_dir->cd(it.fileInfo().absoluteFilePath());
				}
			}
		}
    }

bool ConfigParser::buildConfig()
    {
    /*initialze all objects in UIObjectHandler*/
    this->core->getUIObjectHandler()->initUIObjectHandler();
    *this->file_list = this->config_dir->entryInfoList();
    /*iterate through the file_list entries*/
    for (this->file_list_it = this->file_list->begin(); this->file_list_it != this->file_list->end();++this->file_list_it)
		{
		if((*this->file_list_it).isDir())
			this->file_list->erase(this->file_list_it);
		else
			{
			/*in the case of handling the machine config*/
			if((*this->file_list_it).fileName() == MACHINE_CFG)
				{
				/*get the reference of the machine config*/
				try {
				this->machine_cfg_ref = this->core->getUIObjectHandler()->getMachineConfig();
				} catch (eUnsetPointer &e) {
					this->core->getUIObjectHandler()->initUIObjectHandler();
					this->machine_cfg_ref = this->core->getUIObjectHandler()->getMachineConfig();
					}
				if(!this->validateConfigXMLIntegrity((*this->file_list_it).absoluteFilePath()))
					{
					//qDebug() << "invalid config xml";
					}
				if(this->buildMachineConfig((*this->file_list_it).absoluteFilePath()))
					{
					this->machine_cfg_state = true;
					}
				}
			else if((*this->file_list_it).fileName() == MOD_CFGV)
				{
				this->module_list_ref = this->core->getEventHandler()->getEventMapper()->getModuleList();
				qDebug() << this->module_list_ref->count();
				//qDebug() << "found module config";
				if(this->buildModuleConfig((*this->file_list_it).absoluteFilePath()))
					this->object_cfg_state = true;
				}
			/*in the case of handling the object config*/
			else if((*this->file_list_it).fileName() == OBJ_CFGV)
				{
				try {
				this->screen_list_ref = this->core->getUIObjectHandler()->getScreenList();
				this->buttonc_list_ref = this->core->getUIObjectHandler()->getButtonCList();
				//this->buttont_list_ref = this->core->getUIObjectHandler()->getButtonTList();
				} catch (eUnsetPointer &e) {
					this->core->getUIObjectHandler()->initUIObjectHandler();
					this->screen_list_ref = this->core->getUIObjectHandler()->getScreenList();
					this->buttonc_list_ref = this->core->getUIObjectHandler()->getButtonCList();
					//this->buttont_list_ref = this->core->getUIObjectHandler()->getButtonTList();
					}
				if(this->buildObjects((*this->file_list_it).absoluteFilePath()))
					this->object_cfg_state = true;
				}
			else
				{
				/*waring message for all unexpected configuration files*/
				this->core->configLogWarning(QString(UNEX_CFG_MSG)+" \'"+(*this->file_list_it).fileName()+"\'");
				}
			}
		}

    return true;
    }

/**
  *Parsermethod for the system machine configuration.
  */
bool ConfigParser::buildMachineConfig(const QString machine_cfg)
    {
    QFile config_file(machine_cfg);
    if (!config_file.open(QIODevice::ReadOnly))
		return false;

    QByteArray data = config_file.readAll();
    QDomDocument doc;
    doc.setContent(data);

    QDomNodeList node_list = doc.elementsByTagName(QString(MACHINE_CFG_TAG));
    /*if at least 1 tag was found proceed otherwise return false*/
    if(!node_list.count() > 0)
		{
        this->core->configLogError(QString(MISSING_MACH_TAG));
		return false;
		}
    QDomNode node = node_list.item(node_list.count()-1);
    QDomNamedNodeMap map = node.attributes();
    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == MACHINE_ATTR_ID)
			this->machine_cfg_ref->setID(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_AMID)
			this->machine_cfg_ref->setMachineID(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_TYPE)
			this->machine_cfg_ref->setMachineType(attr.value());
		else if(attr.name() == MACHINE_ATTR_BGFILE)
			this->machine_cfg_ref->setBackgroundFile(attr.value());
		else if(attr.name() == MACHINE_ATTR_BGWIDTH)
			this->machine_cfg_ref->setBackgroundWidth(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_BGHEIGHT)
			this->machine_cfg_ref->setBackgroundHeight(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_MNR)
			this->machine_cfg_ref->setMachineNumber(attr.value());
		else if(attr.name() == MACHINE_ATTR_MTEL)
			this->machine_cfg_ref->setMachineTelNumber(attr.value());
		else
			{
            this->core->configLogWarning(QString(UNHA_ATT_MSG).replace("#_1",attr.name()).replace("#_2",MACHINE_CFG_TAG));
			}
        }
    this->core->configLogInfo(this->machine_cfg_ref->getLogEntryStr());
    return true;
    }

/**
  * Parser method for the layout module configurations.
  * Modules are used to define event handling between objects.
  * A module can consist of several seqeuences.
  * In order to ensure that behavior module attributes has to
  * be append to an existing module with the same adr information.
  * If there is no module existing with the current adr a new one will
  * be created and append to the module list.
  *
  */
bool ConfigParser::buildModuleConfig(const QString mod_cfgv)
	{
    this->module_list_ref->clear();
    QFile obj_file(mod_cfgv);
    if (!obj_file.open(QIODevice::ReadOnly))
		return false;
    QByteArray data = obj_file.readAll();
	QDomDocument doc;
    doc.setContent(data);
    QDomNodeList node_list = doc.elementsByTagName(QString(MODULE_CFG_TAG));
	if(!node_list.count() > 0)
		{
        this->core->configLogError(QString(MISSING_OBJ_TAG));
		return false;
		}
	/*each module*/
	for(int i = 0;i <node_list.count();i++)
		{
		Module *temp_module;
		QDomNode node = node_list.item(i);
		QDomNamedNodeMap map = node.attributes();
		int index = 0;
		bool new_mod = false;
		int adr = this->getModAdrFromTag(map);
		index = this->getModIndexByAdr(adr, this->module_list_ref);
		if( index < 0 )
			{
			new_mod = true;
			temp_module = new Module();
			}
		/*iterate through the attributes*/
		for(uint j = 1; j <= map.length();j++)
			{
			if(map.item(j-1).isAttr())
				{
				QDomAttr attr = map.item(j-1).toAttr();

				if(attr.name() == MODULE_ATTR_MOD_ADR)
					{
					if(new_mod)
						temp_module->setModAdr(attr.value().toInt());
					}
				else if(attr.name() == MODULE_ATTR_SEQ)
					{
					if(new_mod)
						temp_module->addModSeq(attr.value().toInt());
					else
						this->module_list_ref->at(index)->addModSeq(attr.value().toInt());
					}
				else if(attr.name() == MODULE_ATTR_SOURCE)
					{
					if(new_mod)
						temp_module->addModSource(attr.value().toInt());
					else
						this->module_list_ref->at(index)->addModSource(attr.value().toInt());
					}
				else if(attr.name() == MODULE_ATTR_EVENT_IN)
					{
					if(new_mod)
						temp_module->addModEventIn(attr.value());
					else
						this->module_list_ref->at(index)->addModEventIn(attr.value());
					}
				else if(attr.name() == MODULE_ATTR_EVENT_OUT)
					{
					if(new_mod)
						temp_module->addModEventOut(attr.value());
					else
						this->module_list_ref->at(index)->addModEventOut(attr.value());
					}
				else if(attr.name() == MODULE_ATTR_TARGET)
					{
					if(new_mod)
						temp_module->addModTarget(attr.value().toInt());
					else
						this->module_list_ref->at(index)->addModTarget(attr.value().toInt());
					}
				else
					this->core->configLogWarning(QString(UNHA_ATT_MSG).replace("#_1",attr.name()).replace("#_2",MODULE_CFG_TAG));
				}
			}
			if(new_mod)
				this->module_list_ref->append(temp_module);
		}
	for(int i = 0; i < this->module_list_ref->count(); i++)
		{
		this->core->configLogInfo(this->module_list_ref->at(i)->getModLogEntry());
		}
    return true;
	}

/**
 * This method is designed to parse the object config file
 * and to initialize the required objects in the UIObjectHandler
 */
bool ConfigParser::buildObjects(const QString object_cfgv)
    {
    QFile obj_file(object_cfgv);
    if (!obj_file.open(QIODevice::ReadOnly))
		return false;
    QByteArray data = obj_file.readAll();
    QDomDocument doc;
    doc.setContent(data);
    QDomNodeList node_list = doc.elementsByTagName(QString(OBJECT_CFG_TAG));
    /*if at least 1 tag was found proceed otherwise return false*/
    if(!node_list.count() > 0)
		{
        this->core->configLogError(QString(MISSING_OBJ_TAG));
		return false;
		}
    /*iterate through the dom nodes*/
    for(int i = 0;i <node_list.count();i++)
		{
		QDomNode node = node_list.item(i);
		QDomNamedNodeMap map = node.attributes();
		/*iterate through the attributes*/
		for(uint i = 1; i <= map.length();i++)
			{
			if(map.item(i-1).isAttr())
				{
				QDomAttr attr = map.item(i-1).toAttr();
				/* handle the different object types */
				if(attr.name() == OBJECT_CFG_TYPE_ATTR)
					{
					if(attr.value() == OBJECT_TYPE_SCREEN)
						{
						this->buildScreenObject(map);
						}
					else if(attr.value() == OBJECT_TYPE_BUTTON_C)
						{
						this->buildButtonCObject(map);
						}
					else if(attr.value() == OBJECT_TYPE_BUTTON_T)
						{
						//this->buildButtonTObject(map);
						}
					else
						{
						this->core->configLogWarning(QString(UNHA_OBJ_TYPE_MSG).replace("#_1",attr.value())+"in "+object_cfgv+" on line "+QString::number(node.lineNumber()));
						}
					}
				}
			}
		}
    return true;
    }

bool ConfigParser::buildScreenObject(const QDomNamedNodeMap &map)
    {
    ScreenObject* temp = new ScreenObject();

    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == SCREEN_ATTR_ID)
			temp->setObjID(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_PARENT)
			temp->setObjParent(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_TYPE)
			temp->setObjType(attr.value());
		else if(attr.name() == SCREEN_ATTR_NAME)
			temp->setObjName(attr.value());
		else if(attr.name() == SCREEN_ATTR_AUX)
			temp->setObjAux(attr.value());
		else if(attr.name() == SCREEN_ATTR_TIMEOUT)
			temp->setObjTimeout(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_BGIMG)
			{
			temp->setObjBackgroundImage(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
			}
		else if(attr.name() == SCREEN_ATTR_DEF)
			temp->setObjDef(attr.value());
		}
    this->screen_list_ref->append(temp);
    this->core->configLogInfo(this->screen_list_ref->last()->getObjLogEntry());
    return true;
    }

bool ConfigParser::buildButtonCObject(const QDomNamedNodeMap &map)
    {
    ButtonCObject *temp_buttonc = new ButtonCObject();
    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == BUTTON_C_ATTR_ID)
			temp_buttonc->setObjID(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_PARENT)
			temp_buttonc->setObjParent(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_TYPE)
			temp_buttonc->setObjType(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_NAME)
			temp_buttonc->setObjName(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_AUX)
			temp_buttonc->setObjAux(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_XPOS)
			temp_buttonc->setObjXPos(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_YPOS)
			temp_buttonc->setObjYPos(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_UPFILE && attr.value() != "")
			temp_buttonc->setObjUpFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_DOFILE && attr.value() != "")
			temp_buttonc->setObjDoFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_ACT_UPFILE && attr.value() != "")
			temp_buttonc->setObjActUpFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_ACT_DOFILE && attr.value() != "")
			temp_buttonc->setObjActDoFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_TEA_UPFILE && attr.value() != "")
			temp_buttonc->setObjTeaUpFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_TEA_DOFILE && attr.value() != "")
			temp_buttonc->setObjTeaDoFile(QString(this->config_base_dir->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_VISIBLE)
			temp_buttonc->setObjVisible(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_URL_LINK)
			temp_buttonc->setObjUrlLink(attr.value());
		}
    this->buttonc_list_ref->append(temp_buttonc);
    this->core->configLogInfo(this->buttonc_list_ref->last()->getObjLogEntry());
    return true;
    }

/*
bool ConfigParser::buildButtonTObject(const QDomNamedNodeMap &map)
    {
    ButtonTObject *temp_buttont = new ButtonTObject();
    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == BUTTON_T_ATTR_ID)
			temp_buttont->setObjID(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_PARENT)
			temp_buttont->setObjParent(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_TYPE)
			temp_buttont->setObjType(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_NAME)
			temp_buttont->setObjName(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_AUX)
			temp_buttont->setObjAux(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_XPOS)
			temp_buttont->setObjXPos(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_YPOS)
			temp_buttont->setObjYPos(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_TEXT)
			temp_buttont->setObjText(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_FONTSIZE)
			temp_buttont->setObjFontSize(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_XPOSTEXT)
			temp_buttont->setObjXPosText(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_YPOSTEXT)
			temp_buttont->setObjYPosText(attr.value().toInt());
		else if(attr.name() == BUTTON_T_ATTR_FONTCOLOR)
			temp_buttont->setObjFontColor(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_FONT)
			temp_buttont->setObjFont(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_FALIGN)
			temp_buttont->setObjFAlign(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_UPFILE && attr.value() != "")
			temp_buttont->setObjUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_DOFILE && attr.value() != "")
			temp_buttont->setObjDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_ACT_UPFILE && attr.value() != "")
			temp_buttont->setObjActUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_ACT_DOFILE && attr.value() != "")
			temp_buttont->setObjActDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_TEA_UPFILE && attr.value() != "")
			temp_buttont->setObjTeaUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_TEA_DOFILE && attr.value() != "")
			temp_buttont->setObjTeaDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
		else if(attr.name() == BUTTON_T_ATTR_VISIBLE)
			temp_buttont->setObjVisible(attr.value());
		else if(attr.name() == BUTTON_T_ATTR_URL_LINK)
			temp_buttont->setObjUrlLink(attr.value());
		}
    this->buttont_list_ref->append(temp_buttont);
    this->core->configLogInfo(this->buttont_list_ref->last()->getObjLogEntry());
    return true;
    }
*/
bool ConfigParser::validateConfigXMLIntegrity(QString path)
    {
    /*QFile file(path);
    QFile temp_file("config/temp_file.xml");
    file.open(QIODevice::ReadOnly);
    temp_file.open(QIODevice::ReadWrite);

    QString line;
    QTextStream t( &file );
    while ( !t.atEnd() )
        {
        line = t.readLine();
        if(line.contains("version") && !line.contains("encoding"))
            qDebug() << line;
        }
    file.close();
    return false;*/
    return true;
    }


/**
 * searches for an module address in a QList of Module objects
 * returns the index of the module with the address adr or
 * -1 if the address wasn't found
 */
int ConfigParser::getModIndexByAdr(int adr, QList<Module*> *mod_list)
	{

	for(int i = 0; i < mod_list->count();i++)
		{
		if(mod_list->at(i)->getModAdr() == adr)
			{
			return i;
			}
		}
	return -1;

	}

int ConfigParser::getModAdrFromTag(QDomNamedNodeMap map)
	{
	for(uint j = 1; j <= map.length();j++)
			{
			if(map.item(j-1).isAttr())
				{
				QDomAttr attr = map.item(j-1).toAttr();
				if(attr.name() == MODULE_ATTR_MOD_ADR)
					{
					return attr.value().toInt();
					}
				}
			}
	return -1;
	}




#include "configparser.h"

ConfigParser::ConfigParser(CoreEngine *parent) :
    QObject(parent)
{
    this->core = parent;
    this->config_dir = new QDir("");
    this->file_list = new QFileInfoList();
    this->machine_cfg_state = false;
    this->object_cfg_state = false;
    this->module_cfg_state = false;
    }

void ConfigParser::initConfigPath(const QString path)
    {
    this->config_dir->cd(path);
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
		//qDebug() << "found module config";
		}
	    /*in the case of handling the object config*/
	    else if((*this->file_list_it).fileName() == OBJ_CFGV)
		{
		try {
		    this->screen_list_ref = this->core->getUIObjectHandler()->getScreenList();
		    this->buttonc_list_ref = this->core->getUIObjectHandler()->getButtonCList();
		} catch (eUnsetPointer &e) {
		    this->core->getUIObjectHandler()->initUIObjectHandler();
		    this->screen_list_ref = this->core->getUIObjectHandler()->getScreenList();
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
			this->buildScreenObject(map);
		    else if(attr.value() == OBJECT_TYPE_BUTTON_C)
			this->buildButtonCObject(map);
		    else
                        this->core->configLogWarning(QString(UNHA_OBJ_TYPE_MSG).replace("#_1",attr.value())+"in "+object_cfgv+" on line "+QString::number(node.lineNumber()));
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
	if(attr.name() == SCREEN_ATTR_PARENT)
	    temp->setObjParent(attr.value().toInt());
	if(attr.name() == SCREEN_ATTR_TYPE)
	    temp->setObjType(attr.value());
	if(attr.name() == SCREEN_ATTR_NAME)
	    temp->setObjName(attr.value());
	if(attr.name() == SCREEN_ATTR_AUX)
	    temp->setObjAux(attr.value());
	if(attr.name() == SCREEN_ATTR_TIMEOUT)
	    temp->setObjTimeout(attr.value().toInt());
	if(attr.name() == SCREEN_ATTR_BGIMG)
	    {
	    temp->setObjBackgroundImage(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	    //qDebug() << QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value();
	    }
	if(attr.name() == SCREEN_ATTR_DEF)
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
	if(attr.name() == BUTTON_C_ATTR_PARENT)
	    temp_buttonc->setObjParent(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_TYPE)
	    temp_buttonc->setObjType(attr.value());
	if(attr.name() == BUTTON_C_ATTR_NAME)
	    temp_buttonc->setObjName(attr.value());
	if(attr.name() == BUTTON_C_ATTR_AUX)
	    temp_buttonc->setObjAux(attr.value());
	if(attr.name() == BUTTON_C_ATTR_XPOS)
	    temp_buttonc->setObjXPos(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_YPOS)
	    temp_buttonc->setObjYPos(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_UPFILE && attr.value() != "")
	    temp_buttonc->setObjUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_DOFILE && attr.value() != "")
	    temp_buttonc->setObjDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_ACT_UPFILE && attr.value() != "")
	    temp_buttonc->setObjActUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_ACT_DOFILE && attr.value() != "")
	    temp_buttonc->setObjActDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_TEA_UPFILE && attr.value() != "")
	    temp_buttonc->setObjTeaUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_TEA_DOFILE && attr.value() != "")
	    temp_buttonc->setObjTeaDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_C_ATTR_VISIBLE)
	    temp_buttonc->setObjVisible(attr.value());
	if(attr.name() == BUTTON_C_ATTR_URL_LINK)
	    temp_buttonc->setObjUrlLink(attr.value());
	}
    this->buttonc_list_ref->append(temp_buttonc);
    this->core->configLogInfo(this->buttonc_list_ref->last()->getObjLogEntry());
    return true;
    }

bool ConfigParser::buildButtonTObject(const QDomNamedNodeMap &map)
    {
    ButtonTObject *temp_buttont = new ButtonTObject();
    for(uint i = 1; i <= map.length();i++)
	{
	QDomAttr attr = map.item(i-1).toAttr();
	if(attr.name() == BUTTON_T_ATTR_ID)
	    temp_buttont->setObjID(attr.value().toInt());
	if(attr.name() == BUTTON_T_ATTR_PARENT)
	    temp_buttont->setObjParent(attr.value().toInt());
	if(attr.name() == BUTTON_T_ATTR_TYPE)
	    temp_buttont->setObjType(attr.value());
	if(attr.name() == BUTTON_T_ATTR_NAME)
	    temp_buttont->setObjName(attr.value());
	if(attr.name() == BUTTON_T_ATTR_AUX)
	    temp_buttont->setObjAux(attr.value());
	if(attr.name() == BUTTON_T_ATTR_XPOS)
	    temp_buttont->setObjXPos(attr.value().toInt());
	if(attr.name() == BUTTON_T_ATTR_YPOS)
	    temp_buttont->setObjYPos(attr.value().toInt());

	if(attr.name() == BUTTON_T_ATTR_TEXT)
	    temp_buttont->seto(attr.value().toInt());


	if(attr.name() == BUTTON_T_ATTR_UPFILE && attr.value() != "")
	    temp_buttont->setObjUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_DOFILE && attr.value() != "")
	    temp_buttont->setObjDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_ACT_UPFILE && attr.value() != "")
	    temp_buttont->setObjActUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_ACT_DOFILE && attr.value() != "")
	    temp_buttont->setObjActDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_TEA_UPFILE && attr.value() != "")
	    temp_buttont->setObjTeaUpFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_TEA_DOFILE && attr.value() != "")
	    temp_buttont->setObjTeaDoFile(QDir::currentPath()+QString("/")+QString(DEFAULT_WEB_CONTENT_DIR)+attr.value());
	if(attr.name() == BUTTON_T_ATTR_VISIBLE)
	    temp_buttont->setObjVisible(attr.value());
	if(attr.name() == BUTTON_T_ATTR_URL_LINK)
	    temp_buttont->setObjUrlLink(attr.value());
	}
    this->buttonc_list_ref->append(temp_buttonc);
    this->core->configLogInfo(this->buttonc_list_ref->last()->getObjLogEntry());
    return true;
    }


#define BUTTON_T_ATTR_TEXT		"txt"
#define BUTTON_T_ATTR_FONTSIZE		"fontSize"
#define BUTTON_T_ATTR_XPOSTEXT		"xPosText"
#define BUTTON_T_ATTR_YPOSTEXT		"yPosText"
#define BUTTON_T_ATTR_FONTCOLOR		"fontColor"

#define BUTTON_T_ATTR_FONT		"font"
#define BUTTON_T_ATTR_FALIGN		"fAlign"



















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



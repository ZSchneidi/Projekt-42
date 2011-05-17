#include "configparser.h"


ConfigParser::ConfigParser(CoreEngine *parent) :
    QObject(parent)
{
    this->core = parent;
    this->config_dir = new QDir("");
    this->config_base_dir = new QDir("");
    this->file_list = new QFileInfoList();
    this->temp_node_list = new QDomNodeList();
    this->machine_cfg_state = false;
    this->object_cfg_state = false;
    this->module_cfg_state = false;
    }


void ConfigParser::initConfigPath(const QString path)
    {
    if(path == "")
		{
		*this->config_dir = getFirstConfigDir();
		this->config_base_dir->cd(this->config_dir->absolutePath());
		}
	else
		{
		this->config_dir->cd(path);
		this->config_base_dir->cd(path);
		}
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
			{
			this->file_list->erase(this->file_list_it);
			}
		else
			{
			/*in the case of handling the machine config*/
			if((*this->file_list_it).fileName() == MACHINE_CFG)
				{
				this->machine_cfg_ref = this->core->getUIObjectHandler()->getMachineConfig();
				if(!this->validateConfigXMLIntegrity((*this->file_list_it).absoluteFilePath()))
					{
					}
				if(this->buildMachineConfig((*this->file_list_it).absoluteFilePath()))
					{
					this->machine_cfg_state = true;
					}
				}
			/*in the case of handling the module config*/
			else if((*this->file_list_it).fileName() == MOD_CFGV)
				{
				this->module_list_ref = this->core->getEventHandler()->getEventMapper()->getModuleList();
				if(this->buildModuleConfig((*this->file_list_it).absoluteFilePath()))
					{
					this->module_cfg_state = true;
					}
				}
			/*in the case of handling the object config*/
			else if((*this->file_list_it).fileName() == OBJ_CFGV)
				{
				this->screen_list_ref = this->core->getUIObjectHandler()->getScreenList();
				this->buttonc_list_ref = this->core->getUIObjectHandler()->getButtonCList();
				if(this->buildObjects((*this->file_list_it).absoluteFilePath()))
					{
					this->object_cfg_state = true;
					}
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
    this->getNodeList(machine_cfg,MACHINE_CFG_TAG);
    /*if at least 1 tag was found proceed otherwise return false*/
    if(!this->temp_node_list->count() > 0)
		{
        this->core->configLogError(QString(MISSING_MACH_TAG));
		return false;
		}
    QDomNode node = this->temp_node_list->item(this->temp_node_list->count()-1);
    QDomNamedNodeMap map = node.attributes();
    this->machine_cfg_ref->buildMachineConfig(this,map);
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
	this->getNodeList(mod_cfgv,MODULE_CFG_TAG);
	if(!this->temp_node_list->count() > 0)
		{
        this->core->configLogError(QString(MISSING_OBJ_TAG));
		return false;
		}

	/*each module*/
	for(int i = 0;i <this->temp_node_list->count();i++)
		{
		Module *temp_module;
		QDomNode node = this->temp_node_list->item(i);
		QDomNamedNodeMap map = node.attributes();
		int index = 0;
		bool new_mod = false;
		/*get the adr of the module*/
		int adr = this->getModAdrFromTag(map);
		/*search for a module with this adr in the module reference list*/
		index = this->getModIndexByAdr(adr, this->module_list_ref);
		/*if no module was found*/
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
    this->getNodeList(object_cfgv,OBJECT_CFG_TAG);
    /*if at least 1 tag was found proceed otherwise return false*/
    if(!this->temp_node_list->count() > 0)
		{
        this->core->configLogError(QString(MISSING_OBJ_TAG));
		return false;
		}
    /*iterate through the dom nodes*/
    for(int i = 0;i <this->temp_node_list->count();i++)
		{
		QDomNode node = this->temp_node_list->item(i);
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
						ScreenObject* temp_screen = new ScreenObject();
						temp_screen->buildScreenObject(this,map);
						this->screen_list_ref->append(temp_screen);
						this->core->configLogInfo(this->screen_list_ref->last()->getObjLogEntry());
						}
					else if(attr.value() == OBJECT_TYPE_BUTTON_C)
						{
						ButtonCObject *temp_buttonc = new ButtonCObject();
						temp_buttonc->buildButtonCObject(this,map);
						this->buttonc_list_ref->append(temp_buttonc);
						this->core->configLogInfo(this->buttonc_list_ref->last()->getObjLogEntry());
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

/**
  * Returns the address attribute of a module.
  */
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

/**
  * Initialize the temporary node list with the node list of all tags in file
  */
bool ConfigParser::getNodeList(QString file, QString tag)
	{
	QFile config_file(file);
    if (!config_file.open(QIODevice::ReadOnly))
		return false;

    QByteArray data = config_file.readAll();
    QDomDocument doc;
    doc.setContent(data);

    *this->temp_node_list = doc.elementsByTagName(QString(tag));
	return true;
	}


/**
  * Change to the first directory below the config directory
  */
QDir ConfigParser::getFirstConfigDir()
	{
	QDir dir(QCoreApplication::applicationDirPath ());
	dir.cd(DEFAULT_WEB_CFG_SUBDIR);
	QFileInfoList file_inf_list = dir.entryInfoList(QDir::AllDirs,QDir::Reversed);
	foreach (QFileInfo info, file_inf_list)
		{
		if (info.fileName() != "." && info.fileName() != "..")
			{
			dir.cd(info.fileName());
			break;
			}
		}
	return dir;
	}




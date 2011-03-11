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
		    this->machine_cfg = this->core->getUIObjectHandler()->getMachineConfig();
		} catch (eUnsetPointer &e) {
		    this->core->getUIObjectHandler()->initUIObjectHandler();
		    this->machine_cfg = this->core->getUIObjectHandler()->getMachineConfig();
		    }

		if(this->buildMachineConfig((*this->file_list_it).absoluteFilePath()))
		    this->machine_cfg_state = true;
		}
	    else if((*this->file_list_it).fileName() == MOD_CFGV)
		{
		//qDebug() << "found module config";
		}
	    /*in the case of handling the object config*/
	    else if((*this->file_list_it).fileName() == OBJ_CFGV)
		{
		try {
		    this->screen_list = this->core->getUIObjectHandler()->getScreenList();
		} catch (eUnsetPointer &e) {
		    this->core->getUIObjectHandler()->initUIObjectHandler();
		    this->screen_list = this->core->getUIObjectHandler()->getScreenList();
		}
		if(this->buildObjects((*this->file_list_it).absoluteFilePath()))
		    this->object_cfg_state = true;
		}
	    else
		{
		/*waring message for all unexpected configuration files*/
		this->core->logWarning(QString(UNEX_CFG_MSG)+" \'"+(*this->file_list_it).fileName()+"\'");
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
	this->core->logError(QString(MISSING_MACH_TAG));
	return false;
	}
    QDomNode node = node_list.item(node_list.count()-1);
    QDomNamedNodeMap map = node.attributes();
    for(uint i = 1; i <= map.length();i++)
	{
	QDomAttr attr = map.item(i-1).toAttr();
	if(attr.name() == MACHINE_ATTR_ID)
	    this->machine_cfg->setID(attr.value().toInt());
	else if(attr.name() == MACHINE_ATTR_AMID)
	    this->machine_cfg->setMachineID(attr.value().toInt());
	else if(attr.name() == MACHINE_ATTR_TYPE)
	    this->machine_cfg->setMachineType(attr.value());
	else if(attr.name() == MACHINE_ATTR_BGFILE)
	    this->machine_cfg->setBackgroundFile(attr.value());
	else if(attr.name() == MACHINE_ATTR_BGWIDTH)
	    this->machine_cfg->setBackgroundWidth(attr.value().toInt());
	else if(attr.name() == MACHINE_ATTR_BGHEIGHT)
	    this->machine_cfg->setBackgroundHeight(attr.value().toInt());
	else if(attr.name() == MACHINE_ATTR_MNR)
	    this->machine_cfg->setMachineNumber(attr.value());
	else if(attr.name() == MACHINE_ATTR_MTEL)
	    this->machine_cfg->setMachineTelNumber(attr.value());
	else
	    {
	    this->core->logWarning(QString(UNHA_ATT_MSG).replace("#_1",attr.name()).replace("#_2",MACHINE_CFG_TAG));
	    }
	}
    this->core->logInfo(this->machine_cfg->getLogEntryStr());
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
    qDebug() << node_list.count();
    /*if at least 1 tag was found proceed otherwise return false*/
    if(!node_list.count() > 0)
	{
	this->core->logError(QString(MISSING_OBJ_TAG));
	return false;
	}
    for(int i = 0;i <node_list.count();i++)
	{
	QDomNode node = node_list.item(i);
	QDomNamedNodeMap map = node.attributes();
	/*iterate through the attributes*/
	for(uint i = 1; i <= map.length();i++)
	    {
	    QDomAttr attr = map.item(i-1).toAttr();
	    /* handle the different object types */
	    if(attr.name() == SCREEN_ATTR_TYPE)
		{
		if(attr.value() == OBJECT_TYPE_SCREEN)
		    this->buildScreenObject(map);
		else if(attr.value() == OBJECT_TYPE_BUTTON_C)
		    this->buildButtonCObject(map);
		else
		    this->core->logWarning(QString(UNHA_OBJ_TYPE_MSG).replace("#_1",attr.value())+"in "+object_cfgv+" on line "+QString::number(node.lineNumber()));
		}
	    }
	}
    return true;
    }

bool ConfigParser::buildScreenObject(const QDomNamedNodeMap &map)
    {
    ScreenObject temp_screen;
    for(uint i = 1; i <= map.length();i++)
	{
	QDomAttr attr = map.item(i-1).toAttr();
	if(attr.name() == SCREEN_ATTR_ID)
	    temp_screen.setObjID(attr.value().toInt());
	if(attr.name() == SCREEN_ATTR_PARENT)
	    temp_screen.setObjParent(attr.value().toInt());
	if(attr.name() == SCREEN_ATTR_TYPE)
	    temp_screen.setObjType(attr.value());
	if(attr.name() == SCREEN_ATTR_NAME)
	    temp_screen.setObjName(attr.value());
	if(attr.name() == SCREEN_ATTR_AUX)
	    temp_screen.setObjAux(attr.value());
	if(attr.name() == SCREEN_ATTR_TIMEOUT)
	    temp_screen.setObjTimeout(attr.value().toInt());
	if(attr.name() == SCREEN_ATTR_BGIMG)
	    temp_screen.setObjBackgroundImage(attr.value());
	if(attr.name() == SCREEN_ATTR_DEF)
	    temp_screen.setObjDef(attr.value());
	}
    qDebug() << temp_screen.getObjLogEntry();
    this->core->logInfo(temp_screen.getObjLogEntry());
    return true;
    }

bool ConfigParser::buildButtonCObject(const QDomNamedNodeMap &map)
    {
    ButtonCObject temp_buttonc;
    for(uint i = 1; i <= map.length();i++)
	{
	QDomAttr attr = map.item(i-1).toAttr();
	if(attr.name() == BUTTON_C_ATTR_ID)
	    temp_buttonc.setObjID(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_PARENT)
	    temp_buttonc.setObjParent(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_TYPE)
	    temp_buttonc.setObjType(attr.value());
	if(attr.name() == BUTTON_C_ATTR_NAME)
	    temp_buttonc.setObjName(attr.value());
	if(attr.name() == BUTTON_C_ATTR_AUX)
	    temp_buttonc.setObjAux(attr.value());
	if(attr.name() == BUTTON_C_ATTR_XPOS)
	    temp_buttonc.setObjXPos(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_YPOS)
	    temp_buttonc.setObjYPos(attr.value().toInt());
	if(attr.name() == BUTTON_C_ATTR_UPFILE)
	    temp_buttonc.setObjUpFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_DOFILE)
	    temp_buttonc.setObjDoFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_ACT_UPFILE)
	    temp_buttonc.setObjActUpFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_ACT_DOFILE)
	    temp_buttonc.setObjActDoFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_TEA_UPFILE)
	    temp_buttonc.setObjTeaUpFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_TEA_DOFILE)
	    temp_buttonc.setObjTeaDoFile(attr.value());
	if(attr.name() == BUTTON_C_ATTR_VISIBLE)
	    temp_buttonc.setObjVisible(attr.value());
	if(attr.name() == BUTTON_C_ATTR_URL_LINK)
	    temp_buttonc.setObjUrlLink(attr.value());
	}
    qDebug() << temp_buttonc.getObjLogEntry();
    this->core->logInfo(temp_buttonc.getObjLogEntry());
    return true;
    }


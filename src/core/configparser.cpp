#include "configparser.h"

ConfigParser::ConfigParser(CoreEngine *parent) :
    QObject(parent)
{
    this->core = parent;
    this->config_dir = new QDir("");
    this->file_list = new QFileInfoList();

    this->machine_cfg = new MachineConfig;
}

void ConfigParser::initConfigPath(QString path)
{
    this->config_dir->cd(path);
}

bool ConfigParser::buildConfig()
{
    *this->file_list = this->config_dir->entryInfoList();
    /*iterate through the file_list entries*/
    for (this->file_list_it = this->file_list->begin(); this->file_list_it != this->file_list->end();++this->file_list_it)
	{
	if((*this->file_list_it).isDir())
	    this->file_list->erase(this->file_list_it);
	else
	    {
	    if((*this->file_list_it).fileName() == MACHINE_CFG)
		{
		this->buildMachineConfig((*this->file_list_it).absoluteFilePath());
		}
	    else if((*this->file_list_it).fileName() == MOD_CFGV)
		{
		//qDebug() << "found module config";
		}
	    else if((*this->file_list_it).fileName() == OBJ_CFGV)
		{
		//qDebug() << "found obj config";
		}
	    else
		{
		this->core->logWarning(QString(UNEX_CFG_MSG)+" \'"+(*this->file_list_it).fileName()+"\'");
		}
	    }
	}

    return true;
}

bool ConfigParser::buildMachineConfig(QString machine_cfg)
{
    QFile config_file(machine_cfg);
    if (!config_file.open(QIODevice::ReadOnly))
	     return false;
    QByteArray data = config_file.readAll();
    QDomDocument doc;
    doc.setContent(data);
    QDomNodeList node_list = doc.elementsByTagName(QString(MACHINE_CFG_TAG));
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






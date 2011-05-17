#include "machineconfig.h"

MachineConfig::MachineConfig(QObject *parent) :
    QObject(parent)
{
    this->id = 0;
    this->amid = 0;
    this->type = QString("");
    this->background_file = QString("");
    this->background_size = QSize();
    this->mnr = QString("");
    this->mtel = QString("");

	}

bool MachineConfig::buildMachineConfig(ConfigParser *parser, const QDomNamedNodeMap &map)
	{
	for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == MACHINE_ATTR_ID)
			this->setID(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_AMID)
			this->setMachineID(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_TYPE)
			this->setMachineType(attr.value());
		else if(attr.name() == MACHINE_ATTR_BGFILE)
			this->setBackgroundFile(attr.value());
		else if(attr.name() == MACHINE_ATTR_BGWIDTH)
			this->setBackgroundWidth(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_BGHEIGHT)
			this->setBackgroundHeight(attr.value().toInt());
		else if(attr.name() == MACHINE_ATTR_MNR)
			this->setMachineNumber(attr.value());
		else if(attr.name() == MACHINE_ATTR_MTEL)
			this->setMachineTelNumber(attr.value());
		else
			{
            parser->getCore()->configLogWarning(QString(UNHA_ATT_MSG).replace("#_1",attr.name()).replace("#_2",MACHINE_CFG_TAG));
			}
        }
    return true;
	}


/**
  *Builds a string which represents the machine configuration
  */
QString MachineConfig::getLogEntryStr()
	{
    QString temp;
    temp += "Machine definition:\n";
    temp += "\t"+QString(MACHINE_ATTR_ID)+": " + QString::number(this->id)+"\n";
    temp += "\t"+QString(MACHINE_ATTR_AMID)+": " + QString::number(this->amid)+"\n";
    temp += "\t"+QString(MACHINE_ATTR_TYPE)+": " + this->type+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGFILE)+": " + this->background_file+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGWIDTH)+": " + QString::number(this->background_size.width())+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGHEIGHT)+": " + QString::number(this->background_size.height())+"\n";
    temp += "\t"+QString(MACHINE_ATTR_MNR)+": " + this->mnr+"\n";
    temp += "\t"+QString(MACHINE_ATTR_MTEL)+": " + this->mtel;
    return temp;
	}

#include "screenobject.h"

ScreenObject::ScreenObject() :
    QObject()
{
    //this->setFlag(QGraphicsItem::ItemHasNoContents,false);
    this->id = 0;
    this->iparent = 0;
    this->timeout = 0;
    this->aux = QString("");
    this->name = QString("");
    this->def = QString("");
    this->bgimg = QString("");
    this->type = QString("");

	}


bool ScreenObject::buildScreenObject(ConfigParser *parser,const QDomNamedNodeMap &map)
    {

    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == SCREEN_ATTR_ID)
			this->setObjID(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_PARENT)
			this->setObjParent(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_TYPE)
			this->setObjType(attr.value());
		else if(attr.name() == SCREEN_ATTR_NAME)
			this->setObjName(attr.value());
		else if(attr.name() == SCREEN_ATTR_AUX)
			this->setObjAux(attr.value());
		else if(attr.name() == SCREEN_ATTR_TIMEOUT)
			this->setObjTimeout(attr.value().toInt());
		else if(attr.name() == SCREEN_ATTR_BGIMG)
			{
			this->setObjBackgroundImage(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
			}
		else if(attr.name() == SCREEN_ATTR_DEF)
			this->setObjDef(attr.value());
		}
    return true;
    }


QString ScreenObject::getObjLogEntry()
	{
    QString temp;
    temp += "Screen definition:\n";
    temp += "\t"+QString(SCREEN_ATTR_ID)+": " + QString::number(this->id)+"\n";
    temp += "\t"+QString(SCREEN_ATTR_PARENT)+": " + QString::number(this->iparent)+"\n";
    temp += "\t"+QString(SCREEN_ATTR_TYPE)+": " + this->type+"\n";
    temp += "\t"+QString(SCREEN_ATTR_NAME)+": " + this->name+"\n";
    temp += "\t"+QString(SCREEN_ATTR_AUX)+": " +this->aux+"\n";
    temp += "\t"+QString(SCREEN_ATTR_TIMEOUT)+": " + QString::number(this->timeout)+"\n";
    temp += "\t"+QString(SCREEN_ATTR_BGIMG)+": " + this->bgimg+"\n";
    temp += "\t"+QString(SCREEN_ATTR_DEF)+": " + this->def;
    return temp;
	}

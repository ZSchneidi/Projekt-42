#include "buttoncobject.h"

ButtonCObject::ButtonCObject() :
    QObject()
    {
    }

void ButtonCObject::setObjVisible(QString value)
    {
    QList<QString> valid_values;
    valid_values << "Y" << "y" << "N" << "n" << "J" << "j";
    if(valid_values.contains(value))
		{
		this->visible = value;
		}
    }


bool ButtonCObject::buildButtonCObject(ConfigParser *parser, const QDomNamedNodeMap &map)
    {

    for(uint i = 1; i <= map.length();i++)
		{
		QDomAttr attr = map.item(i-1).toAttr();
		if(attr.name() == BUTTON_C_ATTR_ID)
			this->setObjID(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_PARENT)
			this->setObjParent(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_TYPE)
			this->setObjType(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_NAME)
			this->setObjName(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_AUX)
			this->setObjAux(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_XPOS)
			this->setObjXPos(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_YPOS)
			this->setObjYPos(attr.value().toInt());
		else if(attr.name() == BUTTON_C_ATTR_UPFILE && attr.value() != "")
			this->setObjUpFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_DOFILE && attr.value() != "")
			this->setObjDoFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_ACT_UPFILE && attr.value() != "")
			this->setObjActUpFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_ACT_DOFILE && attr.value() != "")
			this->setObjActDoFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_TEA_UPFILE && attr.value() != "")
			this->setObjTeaUpFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_TEA_DOFILE && attr.value() != "")
			this->setObjTeaDoFile(QString(parser->getConfigBaseDir()->absolutePath())+"/"+attr.value());
		else if(attr.name() == BUTTON_C_ATTR_VISIBLE)
			this->setObjVisible(attr.value());
		else if(attr.name() == BUTTON_C_ATTR_URL_LINK)
			this->setObjUrlLink(attr.value());
		}

    return true;
    }


QString ButtonCObject::getObjLogEntry()
    {
    QString temp;
    temp += "Button_C definition:\n";
    temp += "\t"+QString(BUTTON_C_ATTR_ID)+": " + QString::number(this->id)+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_PARENT)+": " + QString::number(this->iparent)+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_TYPE)+": " + this->type+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_NAME)+": " + this->name+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_AUX)+": " +this->aux+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_XPOS)+": " +QString::number(this->x_pos)+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_YPOS)+": " +QString::number(this->y_pos)+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_UPFILE)+": " +this->up_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_DOFILE)+": " +this->do_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_ACT_UPFILE)+": " +this->act_up_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_ACT_DOFILE)+": " +this->act_do_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_TEA_UPFILE)+": " +this->tea_up_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_TEA_DOFILE)+": " +this->tea_do_file+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_VISIBLE)+": " +this->visible+"\n";
    temp += "\t"+QString(BUTTON_C_ATTR_URL_LINK)+": " +this->url_link;
    return temp;
    }

QSize ButtonCObject::getImageSize(QString file_path)
    {
    return QImage(file_path).size();
    }

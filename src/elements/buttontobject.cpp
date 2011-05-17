#include "buttontobject.h"

ButtonTObject::ButtonTObject(QObject *parent) :
    QObject(parent)
{
    }

QString ButtonTObject::getObjLogEntry()
    {
    QString temp;
    temp += "Button_T definition:\n";
    temp += "\t"+QString(BUTTON_T_ATTR_ID)+": " + QString::number(this->id)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_PARENT)+": " + QString::number(this->iparent)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_TYPE)+": " + this->type+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_NAME)+": " + this->name+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_AUX)+": " +this->aux+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_XPOS)+": " +QString::number(this->x_pos)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_YPOS)+": " +QString::number(this->y_pos)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_TEXT)+": " +this->text+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_FONTSIZE)+": " +QString::number(this->font_size)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_XPOSTEXT)+": " +QString::number(this->x_pos_text)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_YPOSTEXT)+": " +QString::number(this->y_pos_text)+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_FONTCOLOR)+": " +this->font_color+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_FONT)+": " +this->font+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_FALIGN)+": " +this->f_align+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_UPFILE)+": " +this->up_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_DOFILE)+": " +this->do_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_ACT_UPFILE)+": " +this->act_up_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_ACT_DOFILE)+": " +this->act_do_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_TEA_UPFILE)+": " +this->tea_up_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_TEA_DOFILE)+": " +this->tea_do_file+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_VISIBLE)+": " +this->visible+"\n";
    temp += "\t"+QString(BUTTON_T_ATTR_URL_LINK)+": " +this->url_link;
    return temp;
    }

QSize ButtonTObject::getImageSize(QString file_path)
    {
    return QImage(file_path).size();
    }

void ButtonTObject::setObjVisible(QString value)
	{
	QList<QString> valid_values;
    valid_values << "Y" << "y" << "N" << "n" << "J" << "j";
    if(valid_values.contains(value))
		{
		this->visible = value;
		}
	}

/*
bool ButtonTObject::buildButtonTObject(const QDomNamedNodeMap &map)
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

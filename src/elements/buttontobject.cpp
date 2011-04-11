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
	this->visible = value;
    else
	qDebug() << "invalid value";
	}

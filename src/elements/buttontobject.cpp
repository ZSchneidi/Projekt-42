#include "buttontobject.h"

ButtonTObject::ButtonTObject(QObject *parent) :
    QObject(parent)
{
    }

QString ButtonTObject::getObjLogEntry()
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

QSize ButtonTObject::getImageSize(QString file_path)
    {
    return QImage(file_path).size();
    }

#include "screenobject.h"

ScreenObject::ScreenObject(QObject *parent) :
    QDeclarativeItem()
{
    this->setFlag(QGraphicsItem::ItemHasNoContents,false);
    this->id = 0;
    this->iparent = 0;
    this->timeout = 0;
    this->aux = QString("");
    this->name = QString("");
    this->def = QString("");
    this->bgimg = QString("");
    this->type = QString("");

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
    temp += "\t"+QString(SCREEN_ATTR_DEF)+": " + this->def+"\n";
    return temp;
}


#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <QDeclarativeItem>

#include "global_define.h"

class ScreenObject : public QDeclarativeItem
{
    Q_OBJECT

private:

    int id;
    int iparent;
    QString type;
    QString name;
    QString aux;
    int timeout;
    QString bgimg;
    QString def;


public:
    explicit ScreenObject(QObject *parent = 0);

    //GETTER
    inline int getObjID() {return this->id;}
    inline int getObjParent() {return this->iparent;}
    inline QString getObjType() {return this->type;}
    inline QString getObjName() {return this->name;}
    inline QString getObjAux() {return this->aux;}
    inline int getObjTimeout() {return this->timeout;}
    inline QString getObjBackgroundImage() {return this->bgimg;}
    inline QString getObjDef() {return this->def;}

    QString getObjLogEntry();

    //SETTER
    inline void setObjID(int id) {this->id = id;}
    inline void setObjParent(int iparent) {this->iparent = iparent;}
    inline void setObjType(QString type) {this->type = type;}
    inline void setObjName(QString name) {this->name = name;}
    inline void setObjAux(QString aux) {this->aux = aux;}
    inline void setObjTimeout(int timeout) {this->timeout = timeout;}
    inline void setObjBackgroundImage(QString bgimg) {this->bgimg = bgimg;}
    inline void setObjDef(QString def) {this->def = def;}

};

#endif // SCREENOBJECT_H

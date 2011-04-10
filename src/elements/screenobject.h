#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <QObject>
#include <QMetaType>

#include "global_define.h"



class ScreenObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getObjID CONSTANT)
    Q_PROPERTY(int iparent READ getObjParent CONSTANT)
    Q_PROPERTY(QString type READ getObjType CONSTANT)
    Q_PROPERTY(QString name READ getObjName CONSTANT)
    Q_PROPERTY(QString aux READ getObjAux CONSTANT)
    Q_PROPERTY(int timeout READ getObjTimeout CONSTANT)
    Q_PROPERTY(QString bgimg READ getObjBackgroundImage CONSTANT)
    Q_PROPERTY(QString def READ getObjDef CONSTANT)

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
    explicit ScreenObject();

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

Q_DECLARE_METATYPE(ScreenObject*)

#endif // SCREENOBJECT_H

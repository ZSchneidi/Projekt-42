#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <QObject>
#include <QMetaType>

#include "global_define.h"
#include "core/configparser.h"

class ConfigParser;


/**
  * A ScreenObject is the respresentation of a screen element.
  * All kinds of buttons etc. are child objects of a screen.
  * The config can provide several screens, which have to displayed in
  * a predefined order. One screen is the default.
  * On button click events it could be necessary to switch to another screen.
  * But this is all view layer logic which is implemented in javascript.
  */
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





public:
    explicit ScreenObject();

    bool buildScreenObject(ConfigParser *parser,const QDomNamedNodeMap &map);

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

private:

    int id;
    int iparent;
    QString type;
    QString name;
    QString aux;
    int timeout;
    QString bgimg;
    QString def;
};

Q_DECLARE_METATYPE(ScreenObject*)

#endif // SCREENOBJECT_H

#ifndef BUTTONCOBJECT_H
#define BUTTONCOBJECT_H

#include <QObject>
#include <QMetaType>
#include <QDeclarativeItem>
#include <QImage>
#include <QDomNamedNodeMap>

#include "global_define.h"
#include "core/configparser.h"

class ConfigParser;

/**
  * This is the representation of a Button_C type object.
  * This type is a basic Button which displays images for various states.
  *
  * This ButtonCObject has a corresponding ButtonC.qml implementation
  * which is used to present a ButtonC in the ViewPort.
  */
class ButtonCObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int id READ getObjID CONSTANT)
    Q_PROPERTY(int iparent READ getObjParent CONSTANT)
    Q_PROPERTY(int x_pos READ getObjXPos CONSTANT)
    Q_PROPERTY(int y_pos READ getObjYPos CONSTANT)
    Q_PROPERTY(QString type READ getObjType CONSTANT)
    Q_PROPERTY(QString name READ getObjName CONSTANT)
    Q_PROPERTY(QString aux READ getObjAux CONSTANT)
    Q_PROPERTY(QString up_file READ getObjUpFile CONSTANT)
    Q_PROPERTY(QString do_file READ getObjDoFile CONSTANT)
    Q_PROPERTY(QString act_up_file READ getObjActUpFile CONSTANT)
    Q_PROPERTY(QString act_do_file READ getObjActDoFile CONSTANT)
    Q_PROPERTY(QString tea_up_file READ getObjTeaUpFile CONSTANT)
    Q_PROPERTY(QString tea_do_file READ getObjTeaDoFile CONSTANT)
    Q_PROPERTY(QString visible READ getObjVisible CONSTANT)
    Q_PROPERTY(QString url_link READ getObjUrlLink CONSTANT)

    int id;
    int iparent;
    int x_pos;
    int y_pos;
    QString type;
    QString name;
    QString aux;
    QString up_file;
    QString do_file;
    QString act_up_file;
    QString act_do_file;
    QString tea_up_file;
    QString tea_do_file;
    QString visible;
    QString url_link;

public:
    explicit ButtonCObject();

    bool buildButtonCObject(ConfigParser *parser, const QDomNamedNodeMap &map);

    //GETTER
    inline int getObjID() {return this->id;}
    inline int getObjParent() {return this->iparent;}
    inline int getObjXPos() {return this->x_pos;}
    inline int getObjYPos() {return this->y_pos;}
    inline QString getObjType() {return this->type;}
    inline QString getObjName() {return this->name;}
    inline QString getObjAux() {return this->aux;}
    inline QString getObjUpFile() {return this->up_file;}
    inline QString getObjDoFile() {return this->do_file;}
    inline QString getObjActUpFile() {return this->act_up_file;}
    inline QString getObjActDoFile() {return this->act_do_file;}
    inline QString getObjTeaUpFile() {return this->tea_up_file;}
    inline QString getObjTeaDoFile() {return this->tea_do_file;}
    inline QString getObjVisible() {return this->visible;}
    inline QString getObjUrlLink() {return this->url_link;}

    Q_INVOKABLE QSize getImageSize(QString file_path);
    QString getObjLogEntry();

    //SETTER
    inline void setObjID(int id) {this->id = id;}
    inline void setObjParent(int iparent) {this->iparent = iparent;}
    inline void setObjXPos(int xpos) {this->x_pos = xpos;}
    inline void setObjYPos(int ypos) {this->y_pos = ypos;}
    inline void setObjType(QString type) {this->type = type;}
    inline void setObjName(QString name) {this->name = name;}
    inline void setObjAux(QString aux) {this->aux = aux;}
    inline void setObjUpFile(QString file) {this->up_file = file;}
    inline void setObjDoFile(QString file) {this->do_file = file;}
    inline void setObjActUpFile(QString file) {this->act_up_file = file;}
    inline void setObjActDoFile(QString file) {this->act_do_file = file;}
    inline void setObjTeaUpFile(QString file) {this->tea_up_file = file;}
    inline void setObjTeaDoFile(QString file) {this->tea_do_file = file;}
    inline void setObjUrlLink(QString link) {this->url_link = link;}
    void setObjVisible(QString value);

};

Q_DECLARE_METATYPE(ButtonCObject*)

#endif // BUTTONCOBJECT_H

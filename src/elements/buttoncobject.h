#ifndef BUTTONCOBJECT_H
#define BUTTONCOBJECT_H

#include <QDeclarativeItem>

#include "global_define.h"

class ButtonCObject
{
    //Q_OBJECT

private:

    int id;
    int iparent;
    QString type;
    QString name;
    QString aux;
    int x_pos;
    int y_pos;
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

    //GETTER
    inline int getObjID() {return this->id;}
    inline int getObjParent() {return this->iparent;}
    inline QString getObjType() {return this->type;}
    inline QString getObjName() {return this->name;}
    inline QString getObjAux() {return this->aux;}
    inline int getObjXPos() {return this->x_pos;}
    inline int getObjYPos() {return this->y_pos;}
    inline QString getObjUpFile() {return this->up_file;}
    inline QString getObjDoFile() {return this->do_file;}
    inline QString getObjActUpFile() {return this->act_up_file;}
    inline QString getObjActDoFile() {return this->act_do_file;}
    inline QString getObjTeaUpFile() {return this->tea_up_file;}
    inline QString getObjTeaDoFile() {return this->tea_do_file;}
    inline QString getObjVisible() {return this->visible;}
    inline QString getObjUrlLink() {return this->url_link;}

    QString getObjLogEntry();

    //SETTER
    inline void setObjID(int id) {this->id = id;}
    inline void setObjParent(int iparent) {this->iparent = iparent;}
    inline void setObjType(QString type) {this->type = type;}
    inline void setObjName(QString name) {this->name = name;}
    inline void setObjAux(QString aux) {this->aux = aux;}
    inline void setObjXPos(int xpos) {this->x_pos = xpos;}
    inline void setObjYPos(int ypos) {this->y_pos = ypos;}
    inline void setObjUpFile(QString file) {this->up_file = file;}
    inline void setObjDoFile(QString file) {this->do_file = file;}
    inline void setObjActUpFile(QString file) {this->act_up_file = file;}
    inline void setObjActDoFile(QString file) {this->act_do_file = file;}
    inline void setObjTeaUpFile(QString file) {this->tea_up_file = file;}
    inline void setObjTeaDoFile(QString file) {this->tea_do_file = file;}
    inline void setObjUrlLink(QString link) {this->url_link = link;}
    void setObjVisible(QString value);

};

#endif // BUTTONCOBJECT_H

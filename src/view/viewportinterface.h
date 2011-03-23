#ifndef VIEWPORTINTERFACE_H
#define VIEWPORTINTERFACE_H

#include <QObject>
#include "view/viewport.h"
#include "core/uiobjecthandler.h"

class ViewPort;

class ViewPortInterface : public QObject
{
    Q_OBJECT

    ViewPort *parent;

    Q_PROPERTY(QUrl sublayer READ getSubLayer() CONSTANT);
    Q_PROPERTY(QString system_time READ getSystemTime() CONSTANT);
    Q_PROPERTY(QString system_date READ getSystemDate() CONSTANT);
    Q_PROPERTY(QString system_title READ getSystemTitle() CONSTANT);


public:
    explicit ViewPortInterface(ViewPort *parent = 0);

    //GETTER
    QUrl getSubLayer();
    inline QString getSystemTime() { return this->system_time; }
    inline QString getSystemDate() { return this->system_date; }
    inline QString getSystemTitle() { return this->system_title; }


    //SETTER
    void setSystemTime(QString time);
    void setSystemDate(QString date);


signals:

    void systemTimeChanged(QString new_time);
    void systemDateChanged(QString new_date);

private slots:

    /*connection from qml*/
    void sendCoreAction( int action);

private:

    QString system_time;
    QString system_date;
    QString system_title;

};

#endif // VIEWPORTINTERFACE_H

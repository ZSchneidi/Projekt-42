#ifndef VIEWPORTINTERFACE_H
#define VIEWPORTINTERFACE_H

#include <QObject>
#include "view/viewport.h"
#include "core/uiobjecthandler.h"
#include "core/exception.h"
#include "elements/product.h"
#include "elements/event.h"

class ViewPort;

/**
  * The ViewPortInterface is a class which is designed as an interface for communication
  * between QML and C++ layer.
  *
  * This Interface provides general system information.
  */
class ViewPortInterface : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl sublayer READ getSubLayer() CONSTANT)
    Q_PROPERTY(QString system_time READ getSystemTime() CONSTANT)
    Q_PROPERTY(QString system_date READ getSystemDate() CONSTANT)
    Q_PROPERTY(QString system_title READ getSystemTitle() CONSTANT)


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

	//Signal caller
	void emitOutEventOnTarget(Event *event);

signals:

    void systemTimeChanged(QString new_time);
    void systemDateChanged(QString new_date);
    void outEventOnTarget(Event *event);

public slots:

    /*connection from qml to c++ logic*/
    void sendCoreAction( int action);
    void sendProductAction(Product *product);
    void sendUiObjectEvent(Event *event);

private:

    ViewPort *parent;

    QString system_time;
    QString system_date;
    QString system_title;

};

#endif // VIEWPORTINTERFACE_H

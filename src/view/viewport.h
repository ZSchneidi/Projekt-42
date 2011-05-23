#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QObject>

#include "global_define.h"
#include "view/viewportinterface.h"
#include "view/webelementinterface.h"
#include "core/coreengine.h"

class CoreEngine;
class ViewPortInterface;
class WebElementInterface;


/**
  * The ViewPort is a major widget which represents a customized version of QDeclarativeview.
  * This widget is designed to paint all qml processes on the screen and is used as the main
  * widget of the application.
  *
  * For communication between QML and C++ layer there are interfaces defined which
  * provide signals, slots and members.
  */
class ViewPort : public QDeclarativeView
{
    Q_OBJECT

public:
    explicit ViewPort(CoreEngine *parent = 0,QUrl path = QUrl(""));

    bool initViewPort();
    void initViewLayer(QUrl source = QUrl(""));

    //GETTER
    inline CoreEngine *getCore() { return this->core; }
    inline QDeclarativeContext *getRootContext() {return this->root_context;}
    inline QUrl getSubLayerPath() { return this->sub_layer_path; }
    inline ViewPortInterface *getViewPortInterface() {return this->interface;}
    inline WebElementInterface *getWebElementInterface() { return this->element_interface; }

    //SETTER
    inline void setSubLayerPath(QUrl source) { this->sub_layer_path = source; }

signals:

public slots:

protected:

    void enterEvent(QEvent *event);

private:

    /**context for the QDeclarative environment*/
    QDeclarativeContext *root_context;

    /**/
    CoreEngine *core;
    /*the interface between C++ and QML layer */
    ViewPortInterface *interface;
    WebElementInterface *element_interface;

    QUrl main_layer_path;
    QUrl sub_layer_path;
    QUrl ui_layer_path;

};

#endif // VIEWPORT_H

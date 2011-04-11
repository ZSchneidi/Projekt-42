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

class ViewPort : public QDeclarativeView
{
    Q_OBJECT


    /**context for the QDeclarative environment*/
    QDeclarativeContext *root_context;

    /**/
    CoreEngine *core;
    /*the interface between C++ and QML layer */
    ViewPortInterface *interface;
    WebElementInterface *element_interface;

    QUrl main_layer_path;
    QUrl sub_layer_path;


public:
    explicit ViewPort(CoreEngine *parent = 0,QUrl path = QUrl(""));

    bool initViewPort();
    void initViewLayer(QUrl source = QUrl(""));

    void initQmlProperties();

    //GETTER
    inline CoreEngine *getCore() { return this->core; }
    inline QDeclarativeContext *getRootContext() {return this->root_context;}
    inline QUrl getSubLayerPath() { return this->sub_layer_path; }
    inline ViewPortInterface *getViewPortInterface() {return this->interface;}

    //SETTER
    inline void setSubLayerPath(QUrl source) { this->sub_layer_path = source; }

signals:

public slots:

private:

    QUrl ui_layer_path;

};

#endif // VIEWPORT_H

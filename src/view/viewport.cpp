#include "viewport.h"
#include <QUrl>

ViewPort::ViewPort(CoreEngine *parent) :
    QDeclarativeView(parent)
{
    this->core = parent;

    /*initialize root_context with the root context of the ViewPort*/
    this->root_context = this->rootContext();

    this->interface = new ViewPortInterface(this);

    /*this manifests the qmlInterface in the qml environment
     *for more informations see qmlinterface.h
     */
    this->root_context->setContextProperty("viewportinterface", this->interface );


    this->setSource(QUrl(MAIN_LAYER_QML));

}

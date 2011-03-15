#include "viewport.h"
#include <QUrl>

ViewPort::ViewPort(CoreEngine *parent, QUrl path) :
    QDeclarativeView(parent)
{
    this->core = parent;
    this->main_layer_path = path;

    this->interface = new ViewPortInterface(this);

    }

bool ViewPort::initViewPort()
    {
    /*initialize root_context with the root context of the ViewPort*/
    this->root_context = this->rootContext();
    /*this manifests the viewportinterface in the qml environment*/
    this->root_context->setContextProperty("viewportinterface", this->interface );

    return true;
    }

void ViewPort::initViewLayer()
    {

    this->setSource(this->main_layer_path);
    }


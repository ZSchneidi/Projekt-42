#include "viewport.h"
#include <QUrl>

ViewPort::ViewPort(CoreEngine *parent, QUrl path) :
    QDeclarativeView(parent)
{
    this->core = parent;
    this->main_layer_path = path;

    this->interface = new ViewPortInterface(this);
    this->element_interface = new WebElementInterface(this);

    }

bool ViewPort::initViewPort()
    {
    /*initialize root_context with the root context of the ViewPort*/
    this->root_context = this->rootContext();
    /*this manifests the viewportinterface in the qml environment*/
    this->root_context->setContextProperty(VIEWPORTINTERFACE, this->interface );
    if(this->core->getInitMode() == CoreEngine::WEB_UI)
        this->root_context->setContextProperty(ELEMENTINTERFACE,this->element_interface);

    qDebug() << this->element_interface->getScreenCount();
    return true;
    }

void ViewPort::initViewLayer(QUrl source)
    {
    this->main_layer_path = source;
    this->setSource(this->main_layer_path);
    }


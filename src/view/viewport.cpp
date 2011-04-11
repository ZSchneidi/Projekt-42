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
    return true;
    }

void ViewPort::initViewLayer(QUrl source)
    {
    this->main_layer_path = source;
    this->setSource(this->main_layer_path);
    }


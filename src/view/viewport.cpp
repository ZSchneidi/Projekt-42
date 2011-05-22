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
    /*do not delete this line, this would result in application crash*/
    this->root_context = this->rootContext();
    return true;
    }

void ViewPort::initViewLayer(QUrl source)
    {
    this->main_layer_path = source;

    //QGLWidget *glWidget = new QGLWidget;


	qDebug() << this->main_layer_path.toString();
	this->core->logSystemMsg("Init main layer: "+this->main_layer_path.toString());
    this->setSource(this->main_layer_path);
}

void ViewPort::enterEvent(QEvent *event)
{
    qDebug() << "entered";
    emit this->getViewPortInterface()->emitInteraction();
}



#include "viewport.h"
#include <QUrl>
#include <QDebug>

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
	this->core->logSystemMsg("Init main layer: "+this->main_layer_path.toString());

    QFile main_layer_file(this->main_layer_path.toLocalFile());
    if(!main_layer_file.exists())
        {
        this->core->logSystemMsg(MISSING_QML_LAYER_MSG);
        QMessageBox::information(0,"Error",MISSING_QML_LAYER_MSG+QString("\nensure that subdir view is present"));
        }
    this->setSource(this->main_layer_path);
}

void ViewPort::enterEvent(QEvent *event)
{
    emit this->getViewPortInterface()->emitInteraction();
}



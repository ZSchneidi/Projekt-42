#include "viewportinterface.h"
#include "global_define.h"

ViewPortInterface::ViewPortInterface(ViewPort *parent) :
    QObject(parent)
    {
    this->parent = parent;


    }

/** this method is designed to send action signals to the core engine*/
void ViewPortInterface::sendCoreAction(int action)
    {
    /*for definition of coreAction take a look at the enum definition in the qmlinterface header*/
    qDebug() << action;
    if(action == 0)
	this->parent->getCore()->close();
    }

QUrl ViewPortInterface::getSubLayer()
    {
    return this->parent->getSubLayerPath();
    }

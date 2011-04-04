#include "webelementinterface.h"

WebElementInterface::WebElementInterface(ViewPort *parent) :
    QObject(parent)
{
    this->parent = parent;
    try {
        this->ui_object_handler = this->parent->getCore()->getUIObjectHandler();
    } catch (...) {

    }

    //this->getScreenCount();
    }

int WebElementInterface::getScreenCount()
    {
    try {
       // qDebug() << this->ui_object_handler->getScreenList()->count();
        return this->ui_object_handler->getScreenList()->count();
    } catch (eUnsetObject &e) {

    }

    }

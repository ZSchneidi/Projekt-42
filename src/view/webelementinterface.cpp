#include "webelementinterface.h"

WebElementInterface::WebElementInterface(ViewPort *parent) :
    QObject(parent)
{
    this->parent = parent;
    try {
        this->ui_object_handler = this->parent->getCore()->getUIObjectHandler();
        this->event_handler = this->parent->getCore()->getEventHandler();
    } catch (...) {

    }

    //this->getScreenCount();
    }

int WebElementInterface::getModuleCount()
	{
	try {
        return this->event_handler->getEventMapper()->getModuleList()->count();
    } catch (eUnsetObject &e) {

	}
    return 0;
	}

int WebElementInterface::getScreenCount()
    {
    try {
        return this->ui_object_handler->getScreenList()->count();
    } catch (eUnsetObject &e) {

	}
    return 0;
    }

ScreenObject *WebElementInterface::getScreenObjectAt(int index)
    {
    if(index >= 0 && index < this->getScreenCount())
	return this->ui_object_handler->getScreenList()->at(index);
    return NULL;
    }

int WebElementInterface::getButtoncCount()
    {
    return this->ui_object_handler->getButtonCList()->count();
    }

ButtonCObject * WebElementInterface::getButtoncObjectAt(int index)
    {
    if(index >= 0 && index < this->getButtoncCount())
	return this->ui_object_handler->getButtonCList()->at(index);
    return NULL;
    }

/*
int WebElementInterface::getButtontCount()
    {
    return this->ui_object_handler->getButtonTList()->count();
    }

ButtonTObject * WebElementInterface::getButtontObjectAt(int index)
    {
    if(index >= 0 && index < this->getButtontCount())
	return this->ui_object_handler->getButtonTList()->at(index);
    return NULL;
    }
*/
Module * WebElementInterface::getModuleAt(int index)
	{
    if(index >= 0 && index < this->getModuleCount())
		return this->event_handler->getEventMapper()->getModuleList()->at(index);
    return NULL;
    }





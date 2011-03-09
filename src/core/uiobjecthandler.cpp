#include "uiobjecthandler.h"

UIObjectHandler::UIObjectHandler(QObject *parent) :
    QObject(parent)
    {
    this->object_handler_state = false;
    this->machine_cfg = NULL;
    }

bool UIObjectHandler::initUIObjectHandler()
    {
    this->machine_cfg = new MachineConfig;

    this->object_handler_state = true;
    return true;
    }

MachineConfig *UIObjectHandler::getMachineConfig()
    {
    if(this->machine_cfg == NULL)
	throw eUnsetPointer();
    return this->machine_cfg;
    }

UIObjectHandler::ScreenList *UIObjectHandler::getScreenList()
    {
    //if(this->screen_list == NULL)
    //	throw eUnsetPointer();
    return this->screen_list;
    }

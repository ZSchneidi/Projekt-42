#include "uiobjecthandler.h"

UIObjectHandler::UIObjectHandler(QObject *parent) :
    QObject(parent)
    {
    this->object_handler_state = false;
    this->screen_list.clear();
    this->buttonc_list.clear();
    }

bool UIObjectHandler::initUIObjectHandler()
    {
    this->machine_cfg = new MachineConfig;
    this->object_handler_state = true;
    return true;
    }

MachineConfig *UIObjectHandler::getMachineConfig()
    {
    return this->machine_cfg;
    }

UIObjectHandler::ScreenList *UIObjectHandler::getScreenList()
    {
    return &this->screen_list;
    }

UIObjectHandler::ButtonCList *UIObjectHandler::getButtonCList()
    {
    return &this->buttonc_list;
    }


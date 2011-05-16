#include "uiobjecthandler.h"

UIObjectHandler::UIObjectHandler(QObject *parent) :
    QObject(parent)
    {
    this->object_handler_state = false;
    this->screen_list.clear();
    this->buttonc_list.clear();
    //this->buttont_list.clear();
    }

bool UIObjectHandler::initUIObjectHandler()
    {
    this->machine_cfg = new MachineConfig;

    this->object_handler_state = true;
    return true;
    }

MachineConfig *UIObjectHandler::getMachineConfig()
    {
    //if(this->state == false)
    //    throw eUnsetObject();
    return this->machine_cfg;
    }

UIObjectHandler::ScreenList *UIObjectHandler::getScreenList()
    {
    //if(this->state == NULL ||this->state == false)
    //    throw eUnsetObject();
    return &this->screen_list;
    }

UIObjectHandler::ButtonCList *UIObjectHandler::getButtonCList()
    {
    //if(this->state == false)
    //    throw eUnsetObject();
    return &this->buttonc_list;
    }

/*
UIObjectHandler::ButtonTList * UIObjectHandler::getButtonTList()
    {
    return &this->buttont_list;
    }
*/

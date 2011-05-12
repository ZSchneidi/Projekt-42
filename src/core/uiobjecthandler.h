#ifndef UIOBJECTHANDLER_H
#define UIOBJECTHANDLER_H

#include <QObject>
#include <QList>
#include <QMetaType>

#include "core/exception.h"
#include "elements/machineconfig.h"
#include "elements/screenobject.h"
#include "elements/buttoncobject.h"
#include "elements/buttontobject.h"
#include "global_define.h"

class MachineConfig;
class ScreenObject;
class ButtonCObject;
class ButtonTObject;

/**
  * The UIObjectHandler is designed to store and provide a complete range
  * of objects based on the XML config files.
  *
  * The ConfigParser is responsible for parsing the config files an build the
  * objects. After creating an object the ConfigParser will store the new object
  * in a list provided by this UIObjectHandler.
  * The View layer will refer these object lists when initializing a WEB_UI.
  * The communication between the view layer and this object handler is
  * implemented in the WebElementInterface which provides access to this
  * model style class from view layer.
  */
class UIObjectHandler : public QObject
{
    Q_OBJECT

public:
    explicit UIObjectHandler(QObject *parent = 0);

    bool initUIObjectHandler();
    typedef QList<ScreenObject*> ScreenList;
    typedef QList<ButtonCObject*> ButtonCList;
    typedef QList<ButtonTObject*> ButtonTList;


public:

    //GETTER
    MachineConfig *getMachineConfig();
    ScreenList *getScreenList();
    ButtonCList *getButtonCList();
    ButtonTList *getButtonTList();
    inline bool getState() { return this->state; }

    //SETTER

    inline void setState(bool state) { this->state = state;}

private:

    bool object_handler_state;

    MachineConfig *machine_cfg;
    ScreenList screen_list;
    ButtonCList buttonc_list;
    ButtonTList buttont_list;

    bool state;
};


Q_DECLARE_METATYPE(QList<ScreenObject*>)

#endif // UIOBJECTHANDLER_H

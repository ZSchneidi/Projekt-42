#ifndef UIOBJECTHANDLER_H
#define UIOBJECTHANDLER_H

#include <QObject>
#include <QList>
#include <QMetaType>

#include "core/exception.h"
#include "elements/machineconfig.h"
#include "elements/screenobject.h"
#include "elements/buttoncobject.h"
#include "global_define.h"

class MachineConfig;
class ScreenObject;
class ButtonCObject;

class UIObjectHandler : public QObject
{
    Q_OBJECT

public:
    explicit UIObjectHandler(QObject *parent = 0);

    bool initUIObjectHandler();

    typedef QList<ScreenObject*> ScreenList;
    typedef QList<ButtonCObject*> ButtonCList;


public:

    //GETTER
    MachineConfig *getMachineConfig();
    ScreenList *getScreenList();
    ButtonCList *getButtonCList();
    inline bool getState() { return this->state; }

    //SETTER

    inline void setState(bool state) { this->state = state;}

private:

    bool object_handler_state;
    MachineConfig *machine_cfg;
    ScreenList screen_list;
    ButtonCList buttonc_list;

    bool state;
};


Q_DECLARE_METATYPE(QList<ScreenObject*>)

#endif // UIOBJECTHANDLER_H

#ifndef UIOBJECTHANDLER_H
#define UIOBJECTHANDLER_H

#include <QObject>
#include <QList>

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

private:

    bool object_handler_state;
    MachineConfig *machine_cfg;
    ScreenList screen_list;
    ButtonCList buttonc_list;

public:

    MachineConfig *getMachineConfig();
    ScreenList *getScreenList();
    ButtonCList *getButtonCList();

};

#endif // UIOBJECTHANDLER_H
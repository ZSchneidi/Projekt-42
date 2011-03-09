#ifndef UIOBJECTHANDLER_H
#define UIOBJECTHANDLER_H

#include <QObject>
#include <QList>

#include "elements/machineconfig.h"
#include "elements/screenobject.h"
#include "global_define.h"

class MachineConfig;
class ScreenObject;

class UIObjectHandler : public QObject
{
    Q_OBJECT

public:
    explicit UIObjectHandler(QObject *parent = 0);

    bool initUIObjectHandler();

    typedef QList<ScreenObject> ScreenList;

private:

    bool object_handler_state;
    MachineConfig *machine_cfg;

    ScreenList *screen_list;

public:

    MachineConfig *getMachineConfig();
    ScreenList *getScreenList();

};

#endif // UIOBJECTHANDLER_H

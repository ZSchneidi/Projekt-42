#ifndef WEBELEMENTINTERFACE_H
#define WEBELEMENTINTERFACE_H

#include <QObject>
#include "view/viewport.h"
#include "core/uiobjecthandler.h"
#include "core/eventhandler.h"
#include "core/eventmapper.h"
#include "core/exception.h"
#include "elements/buttoncobject.h"
#include "elements/screenobject.h"

class ViewPort;
class EventHandler;
class ButtonCObject;
class ScreenObject;
class UIObjectHandler;

/**
  * The WebElementInterface is a class which is designed as an interface for communication
  * between QML and C++ layer.
  *
  * This Interface provides special informations about the objects which were created by the
  * ConfigParser and stored in the UIObjectHandler. These objects are interpreted by the qml layer
  * which refers to this interface to get the information about the existing elements.
  */
class WebElementInterface : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int module_count READ getModuleCount CONSTANT)
    Q_PROPERTY(int screen_count READ getScreenCount CONSTANT)
    Q_PROPERTY(int buttonc_count READ getButtoncCount CONSTANT)

public:
    explicit WebElementInterface(ViewPort *parent = 0);

	int getModuleCount();
    int getScreenCount();
    int getButtoncCount();

    //register Q_INVOKABLE methods as public to provide them directly to the qml layer
    Q_INVOKABLE Module *getModuleAt(int index);
    Q_INVOKABLE ScreenObject *getScreenObjectAt(int index);
    Q_INVOKABLE ButtonCObject *getButtoncObjectAt(int index);

signals:

public slots:

private:
    ViewPort *parent;
    UIObjectHandler *ui_object_handler;
    EventHandler *event_handler;


};

#endif // WEBELEMENTINTERFACE_H

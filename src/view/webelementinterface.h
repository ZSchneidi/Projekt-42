#ifndef WEBELEMENTINTERFACE_H
#define WEBELEMENTINTERFACE_H

#include <QObject>
#include "view/viewport.h"
#include "core/uiobjecthandler.h"
#include "core/exception.h"

class ViewPort;

class WebElementInterface : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int screen_count READ getScreenCount CONSTANT);
    Q_PROPERTY(int buttonc_count READ getButtoncCount CONSTANT);
    Q_PROPERTY(int buttont_count READ getButtontCount CONSTANT);

public:
    explicit WebElementInterface(ViewPort *parent = 0);

    int getScreenCount();
    int getButtoncCount();
    int getButtontCount();

    //register Q_INVOKABLE methods as public to provide them directly to the qml layer
    Q_INVOKABLE ScreenObject *getScreenObjectAt(int index);
    Q_INVOKABLE ButtonCObject *getButtoncObjectAt(int index);
    Q_INVOKABLE ButtonTObject *getButtontObjectAt(int index);

signals:

public slots:

private:
    ViewPort *parent;
    UIObjectHandler *ui_object_handler;


};

#endif // WEBELEMENTINTERFACE_H

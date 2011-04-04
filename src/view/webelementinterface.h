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

public:
    explicit WebElementInterface(ViewPort *parent = 0);

    int getScreenCount();

signals:

public slots:

private:
    ViewPort *parent;
    UIObjectHandler *ui_object_handler;


};

#endif // WEBELEMENTINTERFACE_H

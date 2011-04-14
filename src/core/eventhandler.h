#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>


#include "core/coreengine.h"
#include "core/exception.h"
#include "elements/product.h"


class CoreEngine;

/**
  * The EventHandler is the main contact point for alle kinds of events.
  * One kind of event could be a global key event which is which could be interpreted
  * as application level event like close() or showFullScreen().
  * Another kind of event is a view layer event, which was send by the QML layer.
  * For example a button press event was send by the ViewPortInterface in this case
  * the EventHandler is responsable for delegating this event to low level event handling.
  *
  * In the current state of this projekt there is no further event handling designated!!!
  */
class EventHandler : public QObject
{
    Q_OBJECT

    CoreEngine *core;

public:
    explicit EventHandler(CoreEngine *parent = 0);

    bool processProductAction(Product *product);
    void showWarning(QString msg);

    //Getter
    inline CoreEngine *getCore() { return this->core; }

signals:

public slots:

protected:

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *, QEvent *);


};

#endif // EVENTHANDLER_H

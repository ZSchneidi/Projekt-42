#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QKeyEvent>
#include <QDebug>

#include "core/coreengine.h"
#include "core/exception.h"
#include "elements/product.h"


class CoreEngine;

class EventHandler : public QObject
{
    Q_OBJECT

    CoreEngine *core;

public:
    explicit EventHandler(CoreEngine *parent = 0);

    bool processProductAction(Product *product);

signals:

public slots:

protected:

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *, QEvent *);

};

#endif // EVENTHANDLER_H

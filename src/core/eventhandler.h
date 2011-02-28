#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QKeyEvent>
#include <QDebug>

#include "coreengine.h"

class CoreEngine;

class EventHandler : public QObject
{
    Q_OBJECT

    CoreEngine *core;

public:
    explicit EventHandler(CoreEngine *parent = 0);

signals:

public slots:

protected:

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *, QEvent *);

};

#endif // EVENTHANDLER_H

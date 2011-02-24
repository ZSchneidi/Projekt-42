#ifndef COREENGINE_H
#define COREENGINE_H

#include <QMainWindow>
#include "eventhandler.h"


class EventHandler;

namespace Ui {
    class CoreEngine;
}

class CoreEngine : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoreEngine(QWidget *parent = 0);
    ~CoreEngine();

private:
    Ui::CoreEngine *ui;

    EventHandler *event_handler;

protected:

    void keyPressEvent(QKeyEvent *event);
    CoreEngine *getCore() {return this;}

};

#endif // COREENGINE_H

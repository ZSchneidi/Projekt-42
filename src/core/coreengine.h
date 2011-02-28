#ifndef COREENGINE_H
#define COREENGINE_H

#include <QMainWindow>
#include "eventhandler.h"
#include "global_define.h"
#include "view/viewport.h"

class ViewPort;
class EventHandler;

namespace Ui {
    class CoreEngine;
}

class CoreEngine : public QMainWindow
{
    Q_OBJECT

    ViewPort *declarative_viewport;

public:
    explicit CoreEngine(QWidget *parent = 0);
    ~CoreEngine();

    inline EventHandler* getEventHandler() { return this->event_handler; }

private:
    Ui::CoreEngine *ui;

    EventHandler *event_handler;

    bool setUpMainWindow();


protected:

    void keyPressEvent(QKeyEvent *event);
    CoreEngine *getCore() {return this;}

};

#endif // COREENGINE_H

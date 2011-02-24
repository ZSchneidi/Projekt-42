#include "eventhandler.h"

EventHandler::EventHandler(CoreEngine *parent):
        QObject()
{
    qDebug() << "hello " << parent;
    this->core = parent;
}

void EventHandler::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Key pressed";
}

bool EventHandler::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
        {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->modifiers() == Qt::ControlModifier)
            {
            switch(keyEvent->key())
                {
                case 0x41:
                    qDebug() << "control A was pressed on " << obj;
                    if(!this->core->isMaximized())
                        this->core->showMaximized();
                    else
                        this->core->showNormal();
                    return true;
                default:
                    qDebug() << "unhandled modified key";
                    return false;

                }

           // qDebug() << "event :" << keyEvent->modifiers();
            }
        }
    return false;
}

#include "eventhandler.h"

EventHandler::EventHandler(CoreEngine *parent):
        QObject()
{
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
            qDebug() << "control was pressed on " << keyEvent->key();
            switch(keyEvent->key())
                {
                case TOGGLE_FULLSCREEN_BUTTON:
                    if(!this->core->isFullScreen())
                        this->core->showFullScreen();
                    else
                        this->core->showNormal();
                    return true;
				case TERM_SYSTEM_BUTTON:
					this->core->close();
                default:
                    qDebug() << "unhandled modified key";
                    return false;

                }
            }
        }
    return false;
    }

bool EventHandler::processProductAction(Product *product)
    {
    /*this is an example of a product which emits an unhandled error*/
    if(product->productCode() == 10003)
	return false;
    /*just an temporary example of a product which couldn't served*/
    if(product->productCode() == 10002)
	{
	UnkownProductExpetion myEx;
	myEx.product_code = product->productCode();
	throw myEx;
	}
    else
	{
	/*add product serve logic here*/
	}
    return true;
    }

void EventHandler::showWarning(QString msg = "")
    {
    QMessageBox::warning(0,QString(WARNING_TITLE),QString(msg));
    }

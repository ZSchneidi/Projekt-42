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
    bool product_serve_state = false;

    qDebug() << product->productCode() << product->productName();
    /*this is an example of a product which emits an unhandled error*/
    if(product->productCode() == 10003)
	return false;
    /*just an temporary example of a product which couldn't served*/

    else
	{
	/*add product serve logic here*/
	}

    if(product->productCode() == 0)
	{
	QString err = QString("ERROR: ") + " invalid product code "+ QString::number(product->productCode());
	this->getCore()->getLogHandler()->writeToEventLog(err,LogHandler::PPRODUCT_EVENT);
	}
    else if(product->productCode() > 0 )
	{
	QString success = QString("SUCCESS: ") + QString::number(product->productCode());
	this->getCore()->getLogHandler()->writeToEventLog(success,LogHandler::PPRODUCT_EVENT);
	}
    /*if something unhandled went wrong*/
    else
	{
	QString err = QString("ERROR: an unhandled error occurred : product ") + QString::number(product->productCode());
	this->getCore()->getLogHandler()->writeToEventLog(err,LogHandler::PPRODUCT_EVENT);
	}

    return true;
    }

void EventHandler::showWarning(QString msg = "")
    {
    QMessageBox::warning(0,QString(WARNING_TITLE),QString(msg));
    }

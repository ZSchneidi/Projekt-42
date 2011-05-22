#include "eventhandler.h"

EventHandler::EventHandler(CoreEngine *parent):
    QObject()
{
    this->core = parent;
    this->mapper = new EventMapper(this);

}

void EventHandler::keyPressEvent(QKeyEvent *event)
{
	//qDebug() << event->key();
}

bool EventHandler::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if (keyEvent->modifiers() == Qt::ControlModifier)
        {
			qDebug() << keyEvent->key();
            switch(keyEvent->key())
            {
            case TOGGLE_FULLSCREEN_BUTTON:
                if(!this->core->isFullScreen())
                    this->core->showFullScreen();
                else
                    this->core->showNormal();
                return true;
            case TERM_SYSTEM_BUTTON_C:
            case TERM_SYSTEM_BUTTON_Q:
                this->core->close();
                break;
            case HELP_SYSTEM_BUTTON:
                this->core->showAboutDialog();
                break;
            default:
                return false;
            }
        }
        else
        {
            switch(keyEvent->key())
            {
            case Qt::Key_F1:
                this->core->showHelpDialog();
                return true;
            default:
                return false;
            }
        }
    }
    return false;
}

bool EventHandler::processProductAction(Product *product, Base::Product_state state)
{

    switch(state)
        {
        case Base::Selected:

            qDebug() << "product" << product->productCode() << product->productName() << " selected";
            break;
        case Base::Canceled:
            qDebug() << "product" << product->productCode() << " canceled";
            break;
        case Base::Bought:
            qDebug() << "product" << product->productCode() << " bought";
            break;
        case Base::Served:
            qDebug() << "product" << product->productCode() << " served";
            break;
        case Base::Error:
            qDebug() << "product" << product->productCode() << " error";
            break;
        }

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

bool EventHandler::processUiObjectEvent(Event *event)
{
	QList<int> module_adr_list = this->getEventMapper()->getModuleAdrBySource(event->getSourceID());
	/*interate through all matching modules*/
	for(int i = 0; i < module_adr_list.count() ; i++)
    {

		Module *temp_module = this->getEventMapper()->getModuleByAdr(module_adr_list.at(i));

		QList<QString> event_in_list = temp_module->getModEventInList();

		QString in_event = this->getEventMapper()->getEventDefintion()->getEventStr(event->getEventType());

		/*if the module has an event_in directive matching the incomming event*/
		if(event_in_list.contains(in_event))
        {
			for(int j = 0; j < temp_module->getModSeqList().count(); j++)
            {
				if(temp_module->getModEventIn(j) == in_event)
                {
					Event *out_event = new Event(this);

					out_event->setTargetID(temp_module->getModTarget(j));
					out_event->setEventType(this->getEventMapper()->getEventDefintion()->getEventTypeByStr(temp_module->getModEventOut(j)));

					this->getCore()->getCore()->getViewPort()->getViewPortInterface()->emitOutEventOnTarget(out_event);

                }
            }
        }
    }
	return true;
}











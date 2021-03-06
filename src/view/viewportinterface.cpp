#include "viewportinterface.h"
#include "global_define.h"

ViewPortInterface::ViewPortInterface(ViewPort *parent) :
    QObject(parent)
{
    this->parent = parent;

    this->system_time = "00:00";
    this->system_title = SYSTEM_TITLE;
    this->parent->updatesEnabled();
    }

/** this method is designed to send action signals to the core engine*/
void ViewPortInterface::sendCoreAction(int action)
    {
    /*for definition of coreAction take a look at the enum definition in the qmlinterface header*/
    if(action == 0)
		this->parent->getCore()->close();

    }

QUrl ViewPortInterface::getSubLayer()
    {
    return this->parent->getSubLayerPath();
    }

void ViewPortInterface::setSystemTime(QString time)
    {
    this->system_time = time;
    emit this->systemTimeChanged(this->system_time);
    }

void ViewPortInterface::setSystemDate(QString date)
    {
    this->system_date = date;
    emit this->systemDateChanged(this->system_date);
    }

void ViewPortInterface::sendProductAction(Product *product, int state)
    {
    this->parent->getCore()->getEventHandler()->processProductAction(product,(Base::Product_state)state);
    }

void ViewPortInterface::sendUiObjectEvent(Event *event)
	{
	this->parent->getCore()->getEventHandler()->processUiObjectEvent(event);
	}

void ViewPortInterface::emitOutEventOnTarget(Event *event)
	{
	emit this->outEventOnTarget(event);
	}

void ViewPortInterface::showAboutDialog()
	{
	emit this->aboutDialogCalled(SYS_REVISION,SYS_AUTHOR,SYS_NAME, SYS_HELP_TEXT,SYS_DATE);
	}

bool ViewPortInterface::showHelpDialog()
	{
	QFile help_file(HELP_DIALOG_FILE);
    if (!help_file.open(QIODevice::ReadOnly))
		return false;
	QString text = help_file.readAll();
	emit this->helpDialogCalled(text);
	return true;
    }

void ViewPortInterface::emitInteraction()
    {
    emit this->interact();
    }

void ViewPortInterface::sendMediaAction(int state)
    {
    this->parent->getCore()->getEventHandler()->processMediaAction((Base::Media_states)state);
    }



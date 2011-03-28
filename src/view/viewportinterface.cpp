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
    qDebug() << action;
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

void ViewPortInterface::sendProductAction(Product *product)
    {
    bool product_serve_state = false;
    try
	{
	product_serve_state = this->parent->getCore()->getEventHandler()->processProductAction(product);
	}
    catch (UnkownProductExpetion &e)
	{
	//qDebug() << "expection: " << e.what() << e.product_code;
	QString err = QString("ERROR: ") + e.what() +" "+ QString::number(e.product_code);
	this->parent->getCore()->getLogHandler()->writeToEventLog(err,LogHandler::PPRODUCT_EVENT);
	}
    /*if product was successfully served*/
    if(product_serve_state)
	{
	QString success = QString("SUCCESS: ") + QString::number(product->productCode());
	this->parent->getCore()->getLogHandler()->writeToEventLog(success,LogHandler::PPRODUCT_EVENT);
	}
    /*if something unhandled went wrong*/
    else
	{
	QString err = QString("ERROR: an unhandled error occurred : product ") + QString::number(product->productCode());
	this->parent->getCore()->getLogHandler()->writeToEventLog(err,LogHandler::PPRODUCT_EVENT);
	}

    }

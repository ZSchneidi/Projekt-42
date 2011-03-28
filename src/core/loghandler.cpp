#include "loghandler.h"

LogHandler::LogHandler(QObject *parent) :
    QObject(parent)
    {
    this->system_log = new QFile(LOG_FILE);
    this->event_log = new QFile(EVENT_FILE);
    this->write_mode = QIODevice::Append;

    }

bool LogHandler::writeToSystemLog(QString message, LogHandler::Message_type type)
    {
    if(this->system_log_state == LogHandler::INACTIVE)
	return false;
    if (!this->system_log->open(QIODevice::ReadWrite | this->write_mode))
	return false;
    QString date_time = this->getSystemTimeStr();
    QTextStream log_stream(this->system_log);
    if(type == LogHandler::SYSTEM_LOG)
	{
	log_stream << "["+date_time+"]" << "[SYSTEM] " << message << endl;
	}
    else if(type == LogHandler::WARNING)
	{
	if(this->system_log_state == ACTIVE)
	    log_stream << "["+date_time+"]" << "[WARNING] " << message << endl;
	}
    else if(type == LogHandler::ERROR)
	{
	log_stream << "["+date_time+"]" << "[ERROR] " << message << endl;
	}
    else if(type == LogHandler::INFO)
	{
	if(this->system_log_state == ACTIVE)
	    log_stream << "["+date_time+"]" << "[INFO] " << message << endl;
	}

    this->system_log->close();
    /*this changes the open mode to append, so that the comming lines will be append to the log file*/
    this->write_mode = QIODevice::Append;
    return true;
    }


bool LogHandler::writeToEventLog(QString message, LogHandler::Event_type type)
    {
    if (!this->event_log->open(QIODevice::ReadWrite | QIODevice::Append))
	{
	qDebug() << "cant' access log files!!";
	return false;
	}
    QString date_time = this->getSystemTimeStr();
    QTextStream log_stream(this->event_log);
    if(type == LogHandler::PPRODUCT_EVENT)
	{
	log_stream << "["+date_time+"]" << "[PRODUCT] " << message << endl;
	}


    this->event_log->close();
    return true;
    }

void LogHandler::setLoggerState(Log_state state)
    {
    this->system_log_state = state;
    }

void LogHandler::setLoggerWriteMode(QIODevice::OpenModeFlag mode)
    {
    this->write_mode = mode;
    }

QString LogHandler::getSystemTimeStr()
    {
    QString time = QTime::currentTime().toString(Qt::SystemLocaleLongDate);
    QString date = QDate::currentDate().toString(Qt::SystemLocaleDate);
    QString date_time = date+"-"+time;
    return date_time;
    }


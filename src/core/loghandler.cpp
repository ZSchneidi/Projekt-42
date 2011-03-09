#include "loghandler.h"

LogHandler::LogHandler(QObject *parent) :
    QObject(parent)
    {
    this->system_log = new QFile(LOG_FILE);
    this->write_mode = QIODevice::Append;
    }

bool LogHandler::writeToSystemLog(QString message, LogHandler::Message_type type)
    {
    if(this->system_log_state == LogHandler::INACTIVE)
	return false;
    if (!system_log->open(QIODevice::ReadWrite | this->write_mode))
	return false;
    QString time = QTime::currentTime().toString(Qt::SystemLocaleLongDate);
    QString date = QDate::currentDate().toString(Qt::SystemLocaleDate);
    QString date_time = date+"-"+time;
    QTextStream log_stream(system_log);
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

void LogHandler::setLoggerState(Log_state state)
    {
    this->system_log_state = state;
    }

void LogHandler::setLoggerWriteMode(QIODevice::OpenModeFlag mode)
    {
    this->write_mode = mode;
    }

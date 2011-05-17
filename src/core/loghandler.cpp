#include "loghandler.h"

LogHandler::LogHandler(CoreEngine *parent, Base::Log_state log_state) :
    QObject(parent)
    {
    this->core = parent;
    this->system_log = new QFile(this->core->getCoreAppDirPath()+"/"+SYSTEM_LOG_FILE);
    this->event_log = new QFile(this->core->getCoreAppDirPath()+"/"+EVENT_LOG_FILE);
    this->config_log = new QFile(this->core->getCoreAppDirPath()+"/"+CONFIG_LOG_FILE);
    this->system_log_write_mode = QIODevice::Append;
    this->config_log_write_mode = QIODevice::Append;
    this->system_log_state = Base::LS_Active;
    this->setLoggerState(log_state);
    if(!this->logDirExists())
        {
        this->restoreLogDir();
        }
    }

/**
  * This method can be used to write system messages to the system_log file.
  * The message parameter takes a String which should be logged and
  * type defines the type of system log message.
  */
bool LogHandler::writeToSystemLog(QString message, LogHandler::Message_type type)
    {
    if(this->system_log_state == Base::LS_Inactive)
        return false;
    if (!this->system_log->open(QIODevice::ReadWrite | this->system_log_write_mode))
        return false;
    QString date_time = this->getSystemTimeStr();
    QTextStream log_stream(this->system_log);
    if(type == LogHandler::SYSTEM)
		{
		log_stream << "["+date_time+"]" << "[SYSTEM] " << message << endl;
		}
    else if(type == LogHandler::WARNING && !this->isRestricted())
		{
		log_stream << "["+date_time+"]" << "[WARNING] " << message << endl;
		}
    else if(type == LogHandler::ERROR)
		{
		log_stream << "["+date_time+"]" << "[ERROR] " << message << endl;
		}
    else if(type == LogHandler::INFO && !this->isRestricted())
		{
		log_stream << "["+date_time+"]" << "[INFO] " << message << endl;
		}
    this->system_log->close();
    /*this changes the open mode to append, so that the comming lines will be append to the log file*/
    this->system_log_write_mode = QIODevice::Append;
    return true;
    }

/**
  *	 This method is used to log all kinds of events.
  * Tha event logger is always in append mode. That ensures that event messages
  * will always be written to the end of the log file instead of deleting the file and
  * write a new one.
  */
bool LogHandler::writeToEventLog(QString message, LogHandler::Event_type type)
    {
    if(this->system_log_state == Base::LS_Inactive)
        return false;
    if (!this->event_log->open(QIODevice::ReadWrite | QIODevice::Append))
        {
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

/**
  * This method is used to log messages from the ConfigParser to the config_log file.
  */
bool LogHandler::writeToConfigParserLog(QString message,LogHandler::Parser_Message_type type)
    {
    if(this->system_log_state == Base::LS_Inactive)
        return false;
    if (!this->config_log->open(QIODevice::ReadWrite | this->config_log_write_mode))
        {
        return false;
        }
    QString date_time = this->getSystemTimeStr();
    QTextStream log_stream(this->config_log);
    switch(type)
        {
        case LogHandler::PARSER_INFO:
            log_stream << "["+date_time+"]" << "[INFO] " << message << endl;
            break;
        case LogHandler::PARSER_WARNING:
            log_stream << "["+date_time+"]" << "[WARNING] " << message << endl;
            break;
        case LogHandler::PARSER_ERROR:
            log_stream << "["+date_time+"]" << "[ERROR] " << message << endl;
            break;
        }
    this->config_log->close();
    /*this changes the open mode to append, so that the comming lines will be append to the log file*/
    this->config_log_write_mode = QIODevice::Append;
    return true;
    }

void LogHandler::setLoggerState( Base::Log_state state)
    {
    this->system_log_state = state;
    }

void LogHandler::setLoggerWriteMode(QIODevice::OpenModeFlag mode)
    {
    this->system_log_write_mode = mode;
    this->config_log_write_mode = mode;
    }

QString LogHandler::getSystemTimeStr()
    {
    QString time = QTime::currentTime().toString(Qt::SystemLocaleLongDate);
    QString date = QDate::currentDate().toString(Qt::SystemLocaleDate);
    QString date_time = date+"-"+time;
    return date_time;
    }

bool LogHandler::logDirExists()
    {
    return QDir(this->getCore()->getCoreAppDirPath()+"/"+LOG_DIR).exists();
    }

bool LogHandler::restoreLogDir()
    {
    if(this->system_log_state == Base::LS_Inactive)
		{
        return false;
        }
    return QDir(this->getCore()->getCoreAppDirPath()).mkdir(LOG_DIR);
    }

bool LogHandler::isRestricted()
	{
	if(this->system_log_state == Base::LS_Restricted)
		return true;
	return false;
	}



#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTime>
#include <QDate>


#include "global_define.h"
#include "ext/base.h"
#include "coreengine.h"

class CoreEngine;

/**
  * The LogHandler is designed to write all kinds of logs.
  * System logs are part of the core application.
  * Event logs are written by the EventHandler every time an event was emitted
  * by the view layer.
  * Config logs are written by the ConfigHandler for each object that was created
  * based an the XML config.
  */
class LogHandler : public QObject
	{
    Q_OBJECT

    QIODevice::OpenModeFlag system_log_write_mode;
    QIODevice::OpenModeFlag config_log_write_mode;

public:

    enum Message_type {
        SYSTEM,
		WARNING,
		ERROR,
		INFO
		};

    enum Parser_Message_type {
        PARSER_INFO,
        PARSER_WARNING,
        PARSER_ERROR
        };

    enum Event_type {
		PPRODUCT_EVENT
		};


   // explicit LogHandler(QObject *parent = 0,  Base::Log_state log_state = Base::LS_Active);
    explicit LogHandler(CoreEngine *parent = 0,  Base::Log_state log_state = Base::LS_Active);

    bool writeToSystemLog(QString message, LogHandler::Message_type type);
    bool writeToEventLog(QString message,LogHandler::Event_type);
    bool writeToConfigParserLog(QString message,LogHandler::Parser_Message_type);

    //GETTER
    inline Base::Log_state getLoggerState() { return this->system_log_state; }
    inline CoreEngine *getCore() { return this->core; }

	//SETTER
    void setLoggerState( Base::Log_state state);
    void setLoggerWriteMode(QIODevice::OpenModeFlag);

    bool logDirExists();
    bool restoreLogDir();
    bool isRestricted();

private:

	CoreEngine *core;

    QFile *system_log;
    QFile *event_log;
    QFile *config_log;

	Base::Log_state system_log_state;

    QString getSystemTimeStr();

};

#endif // LOGHANDLER_H

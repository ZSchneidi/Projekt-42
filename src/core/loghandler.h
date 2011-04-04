#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTime>
#include <QDate>

#include "global_define.h"

class LogHandler : public QObject
{
    Q_OBJECT

    QIODevice::OpenModeFlag system_log_write_mode;
    QIODevice::OpenModeFlag config_log_write_mode;

public:
    explicit LogHandler(QObject *parent = 0);

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

    enum Log_state {
	ACTIVE,
	RESTRICTED,
	INACTIVE
	};

    bool writeToSystemLog(QString message, LogHandler::Message_type type);
    bool writeToEventLog(QString message,LogHandler::Event_type);
    bool writeToConfigParserLog(QString message,LogHandler::Parser_Message_type);

    void setLoggerState(Log_state state);
    void setLoggerWriteMode(QIODevice::OpenModeFlag);

    bool logDirExists();
    bool restoreLogDir();

private:

    QFile *system_log;
    QFile *event_log;
    QFile *config_log;

    Log_state system_log_state;

    QString getSystemTimeStr();

};

#endif // LOGHANDLER_H

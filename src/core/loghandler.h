#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QDate>

#include "global_define.h"

class LogHandler : public QObject
{
    Q_OBJECT

    QIODevice::OpenModeFlag write_mode;

public:
    explicit LogHandler(QObject *parent = 0);

    enum Message_type {
	SYSTEM_LOG,
	WARNING,
	ERROR,
	INFO
	};

    enum Log_state {
	ACTIVE,
	RESTRICTED,
	INACTIVE
	};

    bool writeToSystemLog(QString message, LogHandler::Message_type type);
    void setLoggerState(Log_state state);
    void setLoggerWriteMode(QIODevice::OpenModeFlag);

private:

    QFile *system_log;

    Log_state system_log_state;


};

#endif // LOGHANDLER_H

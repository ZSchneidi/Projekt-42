#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <QDebug>

#include <QObject>
#include <QDir>
#include <QUrl>
#include <QFileInfoList>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>

#include "global_define.h"
#include "core/coreengine.h"
#include "elements/machineconfig.h"

class CoreEngine;
class MachineConfig;

class ConfigParser : public QObject
{
    Q_OBJECT

    /*config_dir represents the directory with all configuration files*/
    QDir *config_dir;

    QFileInfoList *file_list;
    QFileInfoList::Iterator file_list_it;

    CoreEngine *core;
    MachineConfig *machine_cfg;

public:
    explicit ConfigParser(CoreEngine *parent = 0);

    //GETTER

    //SETTER
    void initConfigPath(QString path);
    bool buildConfig();
    bool buildMachineConfig(QString machine_cfg);

signals:

public slots:

};

#endif // CONFIGPARSER_H

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
#include <QList>

#include "global_define.h"
#include "core/coreengine.h"
#include "elements/machineconfig.h"
#include "elements/screenobject.h"
#include "core/uiobjecthandler.h"

class CoreEngine;
class MachineConfig;
class ScreenObject;
class UIObjectHandler;

class ConfigParser : public QObject
{
    Q_OBJECT

public:
    explicit ConfigParser(CoreEngine *parent = 0);

    //GETTER

    //SETTER
    void initConfigPath(QString path);

    bool buildConfig();
    bool buildMachineConfig(QString machine_cfg);
    bool buildObjects(QString object_cfgv);
    bool buildScreenObject(QDomNamedNodeMap &map);

signals:

public slots:


private:

    /*config_dir represents the directory with all configuration files*/
    QDir *config_dir;

    QFileInfoList *file_list;
    QFileInfoList::Iterator file_list_it;

    CoreEngine *core;
    MachineConfig *machine_cfg;
    UIObjectHandler::ScreenList *screen_list;

    bool machine_cfg_state;
    bool object_cfg_state;
    bool module_cfg_state;
};

#endif // CONFIGPARSER_H

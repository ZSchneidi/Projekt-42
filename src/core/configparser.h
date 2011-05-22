#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <QDebug>

#include <QObject>
#include <QDir>
#include <QDirIterator>
#include <QUrl>
#include <QFileInfoList>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QList>

#include "global_define.h"
#include "ext/base.h"
#include "core/coreengine.h"
#include "core/uiobjecthandler.h"
#include "core/eventmapper.h"
#include "elements/machineconfig.h"
#include "elements/screenobject.h"
#include "elements/buttoncobject.h"
#include "elements/module.h"

class Base;
class CoreEngine;
class UIObjectHandler;
class EventMapper;
class MachineConfig;
class ScreenObject;
class ButtonCObject;
class Module;


/**
  * The ConfigParser was designed to read a hole XML based config.
  * This config format was defined externally and there is no definition available.
  * What the Config parser does is to search for well known types and parses their
  * attributes to build the corresponding object and store them to the UIObjectHandler.
  *
  */
class ConfigParser : public QObject
{
    Q_OBJECT

public:
    explicit ConfigParser(CoreEngine *parent = 0);

	bool getNodeList(QString file, QString tag);
	QDir getFirstConfigDir();

    //GETTER

	inline CoreEngine *getCore() { return this->core; }
    inline QDir *getConfigBaseDir() { return this->config_base_dir; }
    inline QDir *getConfigDir() { return this->config_dir; }

    //SETTER
    void initConfigPath(const QString path);

    bool buildConfig();
    bool buildMachineConfig(const QString machine_cfg);
    bool buildObjects(const QString object_cfgv);
	bool buildModuleConfig(const QString mod_cfgv);

signals:

public slots:

private:

    /*config_dir represents the directory with all configuration files*/
    QDir *config_dir;
    QDir *config_base_dir;

    QDomNodeList *temp_node_list;

    QFileInfoList *file_list;
    QFileInfoList::Iterator file_list_it;

    CoreEngine *core;
    MachineConfig *machine_cfg_ref;
    EventMapper::ModuleList *module_list_ref;
    QList<ButtonCObject*> *buttonc_list_ref;
    QList<ScreenObject*> *screen_list_ref;

    bool machine_cfg_state;
    bool object_cfg_state;
    bool module_cfg_state;

    int getModIndexByAdr(int adr, QList<Module*> *mod_list);
    int getModAdrFromTag(QDomNamedNodeMap map);

};

#endif // CONFIGPARSER_H

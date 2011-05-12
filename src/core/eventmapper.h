#ifndef EVENTMAPPER_H
#define EVENTMAPPER_H

#include <QObject>
#include "elements/module.h"
#include "core/ext/eventdefinition.h"


/**
  * The EventMapper was designed to provide a complete set of event handling
  * definitions.
  * These definitions are stored as modules in the modulelist.
  * Modules are dynamically build from XML based configurations and are part of
  * the web layout.
  * To manage events between layout objects the modules declare what kind of
  * events are emitted and which objects react to these events.
  * The EventMapper is responsable for controlling the entire event system.
  *
  */
class EventMapper : public QObject
{
    Q_OBJECT


public:


	typedef QList<Module*> ModuleList;

    explicit EventMapper(QObject *parent = 0);

    //GETTER
    ModuleList *getModuleList();

	Module *getModuleByAdr(int adr);
    int getModuleCountBySource(int source);
	QList<int> getModuleAdrBySource(int source);

	EventDefinition *getEventDefintion();

signals:

public slots:

private:

    ModuleList mod_list;
    EventDefinition *event_def;

};

#endif // EVENTMAPPER_H

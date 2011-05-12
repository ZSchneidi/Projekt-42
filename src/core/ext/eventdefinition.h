#ifndef EVENTDEFINITION_H
#define EVENTDEFINITION_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

/**
  * This class was designed to provide string representations of events.
  * Events are basically defined as strings, this class consists of an
  * enum with types which can be used to get the corresponding string
  * out of the definition map.
  *
  */
class EventDefinition : public QObject
{
    Q_OBJECT

public:
    EventDefinition();

	/**
	  * Defines all kinds of events
	  */
	Q_ENUMS(Event_type)
    enum Event_type {
		Blank,
        ButtonDown,
		ButtonUp,
		Hide,
		Show

		};


	Q_INVOKABLE const QString getEventStr(Event_type type);
	Q_INVOKABLE EventDefinition::Event_type getEventTypeByStr(QString string);

private:

	/**
	  * Contains all string representations of events.
	  */
	QMap<QString, Event_type> event_definition_map;

	void initEventDefinitionMap();

};


#endif // EVENTDEFINITION_H

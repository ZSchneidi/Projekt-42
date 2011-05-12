#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include "core/ext/eventdefinition.h"

class Event : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int sourceID READ getSourceID() WRITE setSourceID())
    Q_PROPERTY(int targetID READ getTargetID() WRITE setTargetID())
    Q_PROPERTY(EventDefinition::Event_type eventType READ getEventType() WRITE setEventType())
    Q_PROPERTY(int eventTypeInt READ getEventTypeInt() WRITE setEventTypeInt())

public:
    explicit Event(QObject *parent = 0);

	//GETTER
	Q_INVOKABLE inline int getSourceID() { return this->source_id; }
	Q_INVOKABLE inline int getTargetID() { return this->target_id; }
	Q_INVOKABLE inline EventDefinition::Event_type getEventType() { return this->event_type; }
	Q_INVOKABLE inline int getEventTypeInt() { return (int)this->event_type; }

	//SETTER

	Q_INVOKABLE inline void setSourceID(int source ) { this->source_id =  source; }
	Q_INVOKABLE inline void setTargetID(int target ) { this->target_id =  target; }
	Q_INVOKABLE inline void setEventType(int type ) { this->event_type = (EventDefinition::Event_type)type; }
	Q_INVOKABLE inline void setEventTypeInt(int type ) { this->event_type = (EventDefinition::Event_type)type; }

signals:

public slots:

private:

	int source_id;
	int target_id;
	EventDefinition::Event_type event_type;

};

#endif // EVENT_H

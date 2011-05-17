#include "event.h"

Event::Event(QObject *parent) :
    QObject(parent)
{
	this->source_id = 0;
	this->target_id = 0;
	this->event_type = EventDefinition::Blank;
}

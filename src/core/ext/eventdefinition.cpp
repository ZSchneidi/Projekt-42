#include "eventdefinition.h"

EventDefinition::EventDefinition()
	{
	this->event_definition_map.clear();
	this->initEventDefinitionMap();

	}

const QString EventDefinition::getEventStr(EventDefinition::Event_type type)
	{
	return this->event_definition_map.key(type);
	}

void EventDefinition::initEventDefinitionMap()
	{
	this->event_definition_map.insert("",Blank);
	this->event_definition_map.insert("BtnDo",ButtonDown);
	this->event_definition_map.insert("BtnUp",ButtonUp);
	this->event_definition_map.insert("Hide",Hide);
	this->event_definition_map.insert("Show",Show);

	}

EventDefinition::Event_type EventDefinition::getEventTypeByStr(QString string)
	{
	return this->event_definition_map.find(string).value();
	}


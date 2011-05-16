#include "eventmapper.h"

EventMapper::EventMapper(QObject *parent) :
    QObject(parent)
	{

	this->mod_list.clear();
	this->event_def = new EventDefinition();

	}

EventMapper::ModuleList * EventMapper::getModuleList()
	{
	return &this->mod_list;
	}

int EventMapper::getModuleCountBySource(int source)
	{
	int count = 0;
	for(int i = 0; i < this->mod_list.count(); i++)
		{
		if(this->mod_list.at(i)->getModSourceList().contains(source))
			{
			count++;
			}
		}
	return count;
	}

/**
  * Returns the addresses of the modules which store the event handling
  * for the source object in a QList.
  */
QList<int> EventMapper::getModuleAdrBySource(int source)
	{
	QList<int> adr_list;
	for(int i = 0; i < this->mod_list.count(); i++)
		{
		if(this->mod_list.at(i)->getModSourceList().contains(source))
			{
			adr_list.append(this->mod_list.at(i)->getModAdr());
			}
		}
	return adr_list;
	}

EventDefinition * EventMapper::getEventDefintion()
	{
	return this->event_def;
	}

Module * EventMapper::getModuleByAdr(int adr)
	{
	for(int i = 0; i < this->mod_list.count(); i++)
		{
		if(this->mod_list.at(i)->getModAdr() == adr)
			{
			return this->mod_list.at(i);
			}
		}
	return NULL;
	}

#include "module.h"

Module::Module(QObject *parent) :
    QObject(parent)
	{

	this->mod_adr = 0;
	this->seq.clear();
	this->source.clear();
	this->event_in.clear();
	this->event_out.clear();
	this->target.clear();

	}

QString Module::getModLogEntry()
	{
	QString temp;
    temp += "Module definition:\n";
    temp += "\t"+QString(MODULE_ATTR_MOD_ADR)+": " + QString::number(this->mod_adr)+"\n";
    for(int i = 0; i < this->seq.count(); i++)
		{
		temp += "\t"+QString(MODULE_ATTR_SEQ)+": " + QString::number(this->seq.at(i)) +"\n";
		temp += "\t"+QString(MODULE_ATTR_SOURCE)+": " + QString::number(this->source.at(i))+"\n";
		temp += "\t"+QString(MODULE_ATTR_EVENT_IN)+": " + this->event_in.at(i)+"\n";
		temp += "\t"+QString(MODULE_ATTR_EVENT_OUT)+": " + this->event_out.at(i)+"\n";
		temp += "\t"+QString(MODULE_ATTR_TARGET)+": " + QString::number(this->target.at(i)) +"\n";
		}
    return temp;
	}

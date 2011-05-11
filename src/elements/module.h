#ifndef MODULE_H
#define MODULE_H

#include <QObject>

#include "global_define.h"

/**
  * A Module represents the event handling definition in a config.
  * Modules consits of several sequences which has to be performed
  * sequentially.
  */
class Module : public QObject
{
    Q_OBJECT

	Q_PROPERTY(int mod_adr READ getModAdr() CONSTANT)


public:
    explicit Module(QObject *parent = 0);

    //GETTER
    inline int getModAdr() { return this->mod_adr; }
    inline QList<int> getModSeqList() { return this->seq; }
    inline QList<int> getModSourceList() { return this->source; }
    inline QList<QString> getModEventInList() { return this->event_in; }
    inline QList<QString> getModEventOutList() { return this->event_out; }
    inline QList<int> getModTargetList() { return this->target; }

	QString getModLogEntry();

    //SETTER
    inline void setModAdr(int adr) { this->mod_adr = adr; }
	inline void addModSeq(int seq) { this->seq.append(seq); }
	inline void addModSource(int source) { this->source.append(source); }
	inline void addModEventIn(QString event) { this->event_in.append(event); }
	inline void addModEventOut(QString event) { this->event_out.append(event); }
	inline void addModTarget(int target) { this->target.append(target); }

	Q_INVOKABLE inline int getSeqCount() { return this->seq.count(); }
	Q_INVOKABLE inline int getModSource(int index) { return this->source.at(index); }
	Q_INVOKABLE inline QString getModEventIn(int index) { return this->event_in.at(index); }
	Q_INVOKABLE inline QString getModEventOut(int index) { return this->event_out.at(index); }
	Q_INVOKABLE inline int getModTarget(int index) { return this->target.at(index); }


signals:

public slots:


private:

	int mod_adr;
    QList<int> seq;
    QList<int> source;
    QList<QString> event_in;
    QList<int> target;
    QList<QString> event_out;


};

#endif // MODULE_H

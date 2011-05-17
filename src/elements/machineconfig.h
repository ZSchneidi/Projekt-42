#ifndef MACHINECONFIG_H
#define MACHINECONFIG_H

#include <QObject>
#include <QSize>
#include <QMetaType>
#include <QDomNamedNodeMap>

#include <QDebug>
#include "global_define.h"
#include "core/configparser.h"

class ConfigParser;

/**
  * The MachineConfig represents the configuration of a machine.
  *
  */
class MachineConfig : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int amid READ getMachineID CONSTANT)
    Q_PROPERTY(QString type READ getMachineType CONSTANT)

public:
    explicit MachineConfig(QObject *parent = 0);

	bool buildMachineConfig(ConfigParser *parser,const QDomNamedNodeMap &map);

    //Getter
    inline int getID() {return this->id;}
    inline int getMachineID() {return this->amid;}
    inline QString getMachineType() {return this->type;}
    inline QString getBackgroundFile() {return this->background_file;}
    inline int getBackgroundWidth() {return this->background_size.width();}
    inline int getBackgroundHeight() {return this->background_size.height();}
    inline QSize getBackgroundSize() {return this->background_size;}
    inline QString getMachineNumber() {return this->mnr;}
    inline QString getMachineTelNumber() {return this->mtel;}

    QString getLogEntryStr();

    //Setter
    inline void setID(int id) {this->id = id;}
    inline void setMachineID(int id) {this->amid = id;}
    inline void setMachineType(QString type) {this->type = type;}
    inline void setBackgroundFile(QString file) {this->background_file = file;}
    inline void setBackgroundWidth(int width) {this->background_size.setWidth(width);}
    inline void setBackgroundHeight(int height) {this->background_size.setHeight(height);}
    inline void setBackgroundSize(QSize size) {this->background_size = size;}
    inline void setMachineNumber(QString number) {this->mnr = number;}
    inline void setMachineTelNumber(QString number) {this->mtel = number;}

signals:

public slots:

private:
	int id;
    int amid;
    QString type;
    QString background_file;
    QSize background_size;
    QString mnr;
    QString mtel;

};

//Q_DECLARE_METATYPE(MachineConfig*)

#endif // MACHINECONFIG_H

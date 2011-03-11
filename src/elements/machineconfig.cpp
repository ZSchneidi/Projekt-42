#include "machineconfig.h"

MachineConfig::MachineConfig(QObject *parent) :
    QObject(parent)
{
    this->id = 0;
    this->amid = 0;
    this->type = QString("");
    this->background_file = QString("");
    this->background_size = QSize();
    this->mnr = QString("");
    this->mtel = QString("");

}

/**
  *Builds a string which represents the machine configuration
  */
QString MachineConfig::getLogEntryStr()
{
    QString temp;
    temp += "Machine definition:\n";
    temp += "\t"+QString(MACHINE_ATTR_ID)+": " + QString::number(this->id)+"\n";
    temp += "\t"+QString(MACHINE_ATTR_AMID)+": " + QString::number(this->amid)+"\n";
    temp += "\t"+QString(MACHINE_ATTR_TYPE)+": " + this->type+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGFILE)+": " + this->background_file+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGWIDTH)+": " + QString::number(this->background_size.width())+"\n";
    temp += "\t"+QString(MACHINE_ATTR_BGHEIGHT)+": " + QString::number(this->background_size.height())+"\n";
    temp += "\t"+QString(MACHINE_ATTR_MNR)+": " + this->mnr+"\n";
    temp += "\t"+QString(MACHINE_ATTR_MTEL)+": " + this->mtel;
    return temp;
}

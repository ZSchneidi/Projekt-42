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

QString MachineConfig::getLogEntryStr()
{
    QString temp;
    temp += "Machine definition:\n";
    temp += "\tid: " + QString::number(this->id)+"\n";
    temp += "\tamid: " + QString::number(this->amid)+"\n";
    temp += "\ttype: " + this->type+"\n";
    temp += "\tbgFile: " + this->background_file+"\n";
    temp += "\tbgWidth: " + QString::number(this->background_size.width())+"\n";
    temp += "\tbgHeigth: " + QString::number(this->background_size.height())+"\n";
    temp += "\tmnr: " + this->mnr+"\n";
    temp += "\tmtel: " + this->mtel+"\n";
    return temp;
}

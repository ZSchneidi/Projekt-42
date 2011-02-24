#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
{
    //ui->setupUi(this);

    this->event_handler = new EventHandler(this);
    this->installEventFilter(this->event_handler);
}


void CoreEngine::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Key pressed on core";
}



CoreEngine::~CoreEngine()
{
    delete ui;
}

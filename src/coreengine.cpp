#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
{
    ui->setupUi(this);
}

CoreEngine::~CoreEngine()
{
    delete ui;
}

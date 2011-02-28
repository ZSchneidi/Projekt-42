#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
{
    //ui->setupUi(this);

    this->declarative_viewport = new ViewPort(this);


    this->event_handler = new EventHandler(this);
    this->installEventFilter(this->event_handler);

    this->setUpMainWindow();
}

bool CoreEngine::setUpMainWindow()
{
    /*this fills the parent application window with the qml view*/
    this->declarative_viewport->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    this->setCentralWidget(declarative_viewport);

    return true;
}


void CoreEngine::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Key pressed on core";
}



CoreEngine::~CoreEngine()
{
    delete ui;
}

#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent, InitMode mode, QUrl path) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
    {
    //ui->setupUi(this);
    this->init_mode = mode;
    this->ui_layer_path = path;

    /** Object instances **/
    /*the config_parser is used to build dynamic object and module handler*/
    this->config_parser = new ConfigParser(this);
    /*instantiate the main Viewport for graphical UI as declarative_viewport*/
    this->declarative_viewport = new ViewPort(this);
    /*instantiate an EventHandler which will catch and process every Event send to the Application*/
    this->event_handler = new EventHandler(this);
    /*instantiate a LogHandler which logs all system information etc.*/
    this->log_handler = new LogHandler(this);
    /*instantiate the ui_object_handler this handler is used for prividing custom QML items*/
    this->ui_object_handler = new UIObjectHandler(this);
    /*install the EvenFilter to forward all Events to the EventHandler*/
    this->installEventFilter(this->event_handler);

    this->system_time = new QTime();
    this->system_timer = new QTimer(this);
    this->system_date = new QDate();

    this->initSystemConnections();
    }

void CoreEngine::initSystemConnections()
    {
    connect(this->system_timer,SIGNAL(timeout()),this,SLOT(updateSystemDateTime()));
    }

/**
 *This is the main startup routine.
 */
bool CoreEngine::SystemStartUp()
    {
    QTime time;
    time.start();
    this->startSystemTimer();
    /*startup processes*/
    this->log_handler->writeToSystemLog(SYSTEM_INIT_MSG,LogHandler::SYSTEM_LOG);

    this->initStartup();
    this->setUpViewport();

    this->logSystemMsg("Startup lasts "+QString::number(time.elapsed())+" milliseconds");
    return true;
    }

/**
 * This Method is designed to set up the main Viewport of the Application
 *
 */
bool CoreEngine::setUpViewport()
    {
    this->resize(QSize(800,600));
    this->declarative_viewport->initViewPort();
    /*this fills the parent application window with the qml view*/
    this->declarative_viewport->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    /*define the viewport as main Widget*/
    this->setCentralWidget(declarative_viewport);
    this->declarative_viewport->getRootContext()->setContextProperty("screen_list",QVariant::fromValue(*this->ui_object_handler->getScreenList()));
    this->declarative_viewport->getRootContext()->setContextProperty("machine_config",this->ui_object_handler->getMachineConfig());
    if(this->init_mode == CoreEngine::QML_UI)
        this->ui_layer_path = DEFAULT_QML_LAYER;
    else if (this->init_mode == CoreEngine::WEB_UI)
        this->ui_layer_path = DEFAULT_WEB_LAYER;

    this->declarative_viewport->initViewLayer(QUrl(MAIN_VIEW_LAYER));
    this->updateSystemDateTime();
    return true;
    }

/**
 * This startup method is used to controll the behavior on the application startup.
 */
bool CoreEngine::initStartup()
    {
    switch(this->init_mode)
	{
	case CoreEngine::WEB_UI:
            this->config_parser->initConfigPath(DEFAULT_WEB_CFG_DIR);
            /*parse the config files and build all objects for the UIObjectHandler*/
            this->config_parser->buildConfig();


            this->logSystemMsg(WEB_UI_INIT_MSG);

	    break;
	case CoreEngine::QML_UI:
            this->logSystemMsg(QML_UI_INIT_MSG);
	    break;
	default:

	    break;
	}

    return true;
    }

/**
 * Alternative ways to log messages to system log.
 */
bool CoreEngine::logSystemMsg(const QString message)
    {
    return this->log_handler->writeToSystemLog(message,LogHandler::SYSTEM_LOG);
    }
bool CoreEngine::logWarning(const QString message)
    {
    return this->log_handler->writeToSystemLog(message,LogHandler::WARNING);
    }
bool CoreEngine::logError(const QString message)
    {
    return this->log_handler->writeToSystemLog(message,LogHandler::ERROR);
    }
bool CoreEngine::logInfo(const QString message)
    {
    return this->log_handler->writeToSystemLog(message,LogHandler::INFO);
    }

void CoreEngine::closeEvent(QCloseEvent *)
    {
    this->logSystemMsg(ERROR_APP_CLOSE);
    }

CoreEngine::~CoreEngine()
    {
    delete ui;
    }
/**
 * starts the system timer with an interval of one minute
 */
void CoreEngine::startSystemTimer()
    {
    this->system_timer->start(SYSTEM_TIMER_INTERVAL);
    }
/**
  *is called every time the system timer emits timeout()
  */
void CoreEngine::updateSystemDateTime()
    {
    this->declarative_viewport->getViewPortInterface()->setSystemTime(this->system_time->currentTime().toString(TITLE_TIME_FORMAT));
    this->declarative_viewport->getViewPortInterface()->setSystemDate(this->system_date->currentDate().toString(Qt::TextDate));
    }



#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent, InitMode mode) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
    {
    //ui->setupUi(this);
    this->init_mode = mode;

    /** Object instances **/
    /*the config_parser is used to build dynamic object and module handler*/
    this->config_parser = new ConfigParser(this);
    /*instantiate an EventHandler which will catch and process every Event send to the Application*/
    this->event_handler = new EventHandler(this);
    /*instantiate a LogHandler which logs all system information etc.*/
    this->log_handler = new LogHandler(this);
    /*instantiate the ui_object_handler this handler is used for prividing custom QML items*/
    this->ui_object_handler = new UIObjectHandler(this);
    /*instantiate the main Viewport for graphical UI as declarative_viewport*/
    this->declarative_viewport = new ViewPort(this);
    /*install the EvenFilter to forward all Events to the EventHandler*/
    this->installEventFilter(this->event_handler);

    this->system_time = new QTime();
    this->system_timer = new QTimer(this);
    this->system_date = new QDate();

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
    if(!this->getLogHandler()->logDirExists())
        {
        this->event_handler->showWarning(NO_LOG_DIR);
        }

    this->initSystemConnections();
    this->log_handler->writeToSystemLog(SYSTEM_INIT_MSG,LogHandler::SYSTEM);

    this->initViewEnvironment();
    this->setUpViewport();

    this->logSystemMsg("Startup lasts "+QString::number(time.elapsed())+" milliseconds");
    return true;
    }

/**
 * This startup method is used to controll the behavior on the application startup.
 */
bool CoreEngine::initViewEnvironment()
    {
    switch(this->init_mode)
	{
	case CoreEngine::WEB_UI:
	    this->config_parser->initConfigPath(DEFAULT_WEB_CFG_DIR);
	    /*parse the config files and build all objects for the UIObjectHandler*/
	    this->config_parser->buildConfig();


            this->declarative_viewport->setSubLayerPath(QUrl(DEFAULT_WEB_LAYER));
	    this->logSystemMsg(WEB_UI_INIT_MSG);

	    break;
	case CoreEngine::QML_UI:
            this->declarative_viewport->setSubLayerPath(QUrl(DEFAULT_QML_LAYER));
	    this->logSystemMsg(QML_UI_INIT_MSG);
	    break;
	default:

	    break;
	}

    return true;
    }

/**
 *  is designed to set up the main Viewport of the Application
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
    /*this step is important to ensure that all data and custom types are registered to the qml environment*/
    this->registerQmlTypes();
    this->declarative_viewport->initViewLayer(QUrl(MAIN_VIEW_LAYER));
    this->updateSystemDateTime();
    return true;
    }


/**
  * This method is called to register custom c++ types to the qml environment
  */
void CoreEngine::registerQmlTypes()
    {
    this->declarative_viewport->getRootContext()->setContextProperty("screen_list",QVariant::fromValue(*this->ui_object_handler->getScreenList()));
    this->declarative_viewport->getRootContext()->setContextProperty("machine_config",this->ui_object_handler->getMachineConfig());
    /*this manifests the viewportinterface in the qml environment*/
    this->declarative_viewport->getRootContext()->setContextProperty(VIEWPORTINTERFACE, this->declarative_viewport->getViewPortInterface() );
    if(this->getInitMode() == CoreEngine::WEB_UI)
	this->declarative_viewport->getRootContext()->setContextProperty(ELEMENTINTERFACE,this->declarative_viewport->getWebElementInterface());
    qmlRegisterType<Product>("Product", 0,1, "Product");
    qmlRegisterType<ScreenObject>("ScreenObject", 0,1, "ScreenObject");
    qmlRegisterType<ButtonCObject>("ButtonC", 0,1, "ButtonC");
    }


/**
 * Alternative ways to log messages to log files.
 */
bool CoreEngine::logSystemMsg(const QString message)
    {
    return this->log_handler->writeToSystemLog(message,LogHandler::SYSTEM);
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
bool CoreEngine::configLogInfo(const QString message)
    {
    return this->log_handler->writeToConfigParserLog(message,LogHandler::PARSER_INFO);
    }
bool CoreEngine::configLogWarning(const QString message)
    {
    return this->log_handler->writeToConfigParserLog(message,LogHandler::PARSER_WARNING);
    }
bool CoreEngine::configLogError(const QString message)
    {
    return this->log_handler->writeToConfigParserLog(message,LogHandler::PARSER_ERROR);
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
    this->declarative_viewport->getViewPortInterface()->setSystemDate(this->system_date->currentDate().toString(Qt::DefaultLocaleLongDate));
    }

UIObjectHandler *CoreEngine::getUIObjectHandler()
    {
    //if(this->ui_object_handler->getState() == false)
     //   throw eUnsetObject();
    //else
    return this->ui_object_handler;
    }





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
    this->declarative_viewport = new ViewPort(this,this->ui_layer_path);
    /*instantiate an EventHandler which will catch and process every Event send to the Application*/
    this->event_handler = new EventHandler(this);
    /*instantiate a LogHandler which logs all system information etc.*/
    this->log_handler = new LogHandler(this);
    /*instantiate the ui_object_handler this handler is used for prividing custom QML items*/
    this->ui_object_handler = new UIObjectHandler(this);
    /*install the EvenFilter to forward all Events to the EventHandler*/
    this->installEventFilter(this->event_handler);

    }

/**
 *This is the main startup routine.
 */
bool CoreEngine::SystemStartUp()
    {
    QTime time;
    time.start();
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
    this->declarative_viewport->initViewPort();
    /*this fills the parent application window with the qml view*/
    this->declarative_viewport->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    /*define the viewport as main Widget*/
    this->setCentralWidget(declarative_viewport);

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
	    this->config_parser->buildConfig();
	    this->log_handler->writeToSystemLog(WEB_UI_INIT_MSG,LogHandler::SYSTEM_LOG);
	    break;
	case CoreEngine::QML_UI:

	    this->log_handler->writeToSystemLog(QML_UI_INIT_MSG,LogHandler::SYSTEM_LOG);
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

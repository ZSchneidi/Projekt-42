#include "coreengine.h"
#include "ui_coreengine.h"

CoreEngine::CoreEngine(QWidget *parent, InitMode mode, Base::Log_state log_state, QString config_path) :
    QMainWindow(parent),
    ui(new Ui::CoreEngine)
{
    this->init_mode = mode;
    this->config_path = config_path;

    /** Object instances **/
    /*the config_parser is used to build dynamic object and module handler*/
    this->config_parser = new ConfigParser(this);
    /*instantiate an EventHandler which will catch and process every Event send to the Application*/
    this->event_handler = new EventHandler(this);
    /*instantiate a LogHandler which logs all system information etc.*/
    this->log_handler = new LogHandler(this,log_state);
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


/**
 * The main startup routine.
 */
bool CoreEngine::SystemStartUp(const QSize size, const Qt::WindowState window_state)
    {
    QTime time;
    time.start();
    this->startSystemTimer();
    /*startup processes*/
    if(!this->getLogHandler()->logDirExists() && !this->getLogHandler()->getLoggerState() == Base::LS_Inactive)
        {
        this->event_handler->showWarning(NO_LOG_DIR);
        }
    this->initSystemConnections();
    this->log_handler->writeToSystemLog(SYSTEM_INIT_MSG,LogHandler::SYSTEM);
    this->initViewEnvironment();
    this->setUpViewport(size,window_state);
    this->logSystemMsg("Startup lasts "+QString::number(time.elapsed())+" milliseconds");
    return true;
    }

/**
  * Used to connect all SIGNAL SLOT relations for the application
  */
void CoreEngine::initSystemConnections()
    {
    connect(this->system_timer,SIGNAL(timeout()),this,SLOT(updateSystemDateTime()));
    }

/**
 * This startup method is used to controll the behavior on the application startup.
 */
bool CoreEngine::initViewEnvironment()
    {
    switch(this->init_mode)
		{
		case CoreEngine::WEB_UI:
			/*change the directory of the config_parser to*/
			if(this->config_path != "")
				{
				this->config_parser->initConfigPath(this->config_path);
				}
			else
				{
				this->config_parser->initConfigPath("");
				}
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
bool CoreEngine::setUpViewport(const QSize size, const Qt::WindowState window_state)
    {
    if(window_state != Qt::WindowNoState)
		{
		this->setWindowState(window_state);
		}
	else
		{
		this->resize(QSize(size.width(),size.height()));
		}
    this->declarative_viewport->initViewPort();
    /*this fills the parent application window with the qml view*/
    this->declarative_viewport->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    /*define the viewport as main Widget*/
    this->setCentralWidget(declarative_viewport);
    /*this step is important to ensure that all data and custom types are registered to the qml environment*/
    this->registerQmlTypes();
    this->declarative_viewport->initViewLayer(QUrl(QCoreApplication::applicationDirPath ()+"/"+MAIN_VIEW_LAYER));
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
    qmlRegisterType<Module>("Module", 0,1, "Module");
    qmlRegisterType<Product>("Product", 0,1, "Product");
    qmlRegisterType<ScreenObject>("ScreenObject", 0,1, "ScreenObject");
    qmlRegisterType<ButtonCObject>("ButtonC", 0,1, "ButtonC");
    qmlRegisterType<Event>("Event",0,1,"Event");
    qmlRegisterType<EventDefinition>("EventDefinition",0,1,"EventDefinition");
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
    delete this->config_parser;
    delete this->event_handler;
    delete this->log_handler;
    delete this->ui_object_handler;
    delete this->declarative_viewport;
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
    this->declarative_viewport->getViewPortInterface()->setSystemDate(this->system_date->currentDate().toString(TITLE_DATE_FORMAT));
    }

UIObjectHandler *CoreEngine::getUIObjectHandler()
    {
    return this->ui_object_handler;
    }

/**
  * The HelpDialog is provided on qml layer.
  * Because of that the core will call the viewportinterface to show
  * the HelpDialog.
  */
void CoreEngine::showAboutDialog()
	{

	this->getViewPort()->getViewPortInterface()->showAboutDialog();
	}

void CoreEngine::showHelpDialog()
	{
	if(!this->getViewPort()->getViewPortInterface()->showHelpDialog())
		{
		qDebug() << "can't read help file";
		}

	}


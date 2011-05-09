#include <QtGui/QApplication>
#include "core/coreengine.h"
#include "core/loghandler.h"
#include "elements/screenobject.h"

QString getHelpText();

int main(int argc, char *argv[])
    {
    QApplication a(argc, argv);

	QStringList arguments = a.arguments();

	qDebug() << arguments;


	/* ARGUMENTS */
	if(arguments.contains(ARG_HELP))
		{
		QMessageBox::information(0,"Help",getHelpText());
		return 0;
		}

	/*initialize InitMode depending on the argument QML_UI is default */
	CoreEngine::InitMode mode = CoreEngine::QML_UI;
	if(arguments.contains(ARG_WEB_UI))
		{
		mode = CoreEngine::WEB_UI;
		}
	else 	if(arguments.contains(ARG_QML_UI))
		{
		mode = CoreEngine::QML_UI;
		}

	/*init LogHandler state*/
	LogHandler::Log_state log_state = LogHandler::ACTIVE;
	if(arguments.contains(ARG_LOG_STATE_ACTIVE))
		{
		log_state = LogHandler::ACTIVE;
		}
	else 	if(arguments.contains(ARG_LOG_STATE_RESTRICTED))
		{
		log_state = LogHandler::RESTRICTED;
		}
	else 	if(arguments.contains(ARG_LOG_STATE_INACTIVE))
		{
		log_state = LogHandler::INACTIVE;
		}

	/*display size*/
	Qt::WindowState windows_state;
	QSize window_size = QSize(SYSTEM_VIEWPORT_WIDTH,SYSTEM_VIEWPORT_HEIGHT);
	if(arguments.contains(ARG_FULLSCREEN))
		{
		windows_state = Qt::WindowFullScreen;
		}

	/*getting a size if available*/
	for (int i = 0; i < arguments.size(); i++)
		{
		if(arguments.at(i).contains(ARG_SCREEN_SIZE))
			{
			QString size_str =  arguments.at(i);
			QStringList size_list =  size_str.remove(ARG_SCREEN_SIZE).split("x");
			window_size.setWidth(size_list.at(0).toInt());
			window_size.setHeight(size_list.at(1).toInt());
			}
		}

	/* ARGUMENTS FINISHED */

	a.setGraphicsSystem("raster");

    QIODevice::OpenModeFlag open_mode = QIODevice::Truncate;

    CoreEngine w(0,mode,log_state);

    w.getLogHandler()->setLoggerState(log_state);
    w.getLogHandler()->setLoggerWriteMode(open_mode);
    /*call the startup routine*/
    w.SystemStartUp(window_size,windows_state);

    w.show();

    return a.exec();
    }


/**
 *builds the command argument help text.
 */
QString getHelpText()
    {
    QString ret_str;
    ret_str += QString("valid arguments are: \n");
    ret_str += QString(ARG_HELP" - shows this message\n");
    ret_str += QString("\nUI mode \n");
    ret_str += QString(ARG_WEB_UI" - application will start with Web style interface \n");
    ret_str += QString(ARG_QML_UI" - application will start with QML interface \n");
    ret_str += QString("\nLogger state \n");
    ret_str += QString(ARG_LOG_STATE_ACTIVE" - log everything\n");
    ret_str += QString(ARG_LOG_STATE_RESTRICTED" - log only SYSTEM and ERROR messages\n");
    ret_str += QString(ARG_LOG_STATE_INACTIVE" - disable log \n");
    ret_str += QString("\nDisplay options \n");
    ret_str += QString(ARG_SCREEN_SIZE"WidthxHeight - used to init the viewport with the defined size \n");
    return ret_str;
    }






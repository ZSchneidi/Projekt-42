#include <QtGui/QApplication>
#include "core/coreengine.h"
#include "core/loghandler.h"
#include "elements/screenobject.h"

QString getHelpText();

int main(int argc, char *argv[])
    {
    QApplication::setGraphicsSystem("raster");
    QApplication a(argc, argv);

	QStringList arguments = a.arguments();
    QString used_arguments = "";

	/* ARGUMENTS */
	if(arguments.contains(ARG_HELP))
		{
		QMessageBox::information(0,"Help",getHelpText());
		used_arguments += ARG_HELP;
		return 0;
		}

	/*initialize InitMode depending on the argument QML_UI is default */

	CoreEngine::InitMode mode = CoreEngine::QML_UI;
	QString conf_path = "";
	if(arguments.contains(ARG_WEB_UI))
		{
		used_arguments += ARG_WEB_UI;
		mode = CoreEngine::WEB_UI;
		/*search for specific config path*/
		for (int i = 0; i < arguments.size(); i++)
			{
			if(arguments.at(i).contains(ARG_WEB_CONFIG))
				{
				used_arguments += arguments.at(i);
				conf_path =  arguments.at(i);
				conf_path =  conf_path.remove(ARG_WEB_CONFIG);
				}
			}
		}
	else 	if(arguments.contains(ARG_QML_UI))
		{
		used_arguments += ARG_QML_UI;
		mode = CoreEngine::QML_UI;
		}

	/*init LogHandler state*/
	Base::Log_state log_state = Base::LS_Active;
	if(arguments.contains(ARG_LOG_STATE_ACTIVE))
		{
		used_arguments += ARG_LOG_STATE_ACTIVE;
		log_state = Base::LS_Active;
		}
	else 	if(arguments.contains(ARG_LOG_STATE_RESTRICTED))
		{
		used_arguments += ARG_LOG_STATE_RESTRICTED;
		log_state = Base::LS_Restricted;
		}
	else 	if(arguments.contains(ARG_LOG_STATE_INACTIVE))
		{
		used_arguments += ARG_LOG_STATE_INACTIVE;
		log_state = Base::LS_Inactive;
		}

	/*display size*/
	Qt::WindowState windows_state = Qt::WindowNoState;
	QSize window_size = QSize(SYSTEM_VIEWPORT_WIDTH,SYSTEM_VIEWPORT_HEIGHT);
	if(arguments.contains(ARG_FULLSCREEN))
		{
		used_arguments += ARG_FULLSCREEN;
		windows_state = Qt::WindowFullScreen;
		}

	/*getting a size if available*/
	for (int i = 0; i < arguments.size(); i++)
		{
		if(arguments.at(i).contains(ARG_SCREEN_SIZE))
			{
			used_arguments += arguments.at(i);
			QString size_str =  arguments.at(i);
			QStringList size_list =  size_str.remove(ARG_SCREEN_SIZE).split("x");
			window_size.setWidth(size_list.at(0).toInt());
			window_size.setHeight(size_list.at(1).toInt());
			}
		}

	/* ARGUMENTS FINISHED */

    QIODevice::OpenModeFlag open_mode = QIODevice::Truncate;

    CoreEngine w(0,mode,log_state,conf_path);

    w.getLogHandler()->setLoggerState(log_state);
    w.getLogHandler()->setLoggerWriteMode(open_mode);
    w.getLogHandler()->writeToSystemLog(QString(SYSTEM_ARG_MSG+used_arguments),LogHandler::SYSTEM);
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
    ret_str += QString(ARG_WEB_CONFIG"source - you can use this argument to specify the content directory you wanna use \n");
    ret_str += QString(ARG_QML_UI" - application will start with QML interface \n");
    ret_str += QString("\nLogger state \n");
    ret_str += QString(ARG_LOG_STATE_ACTIVE" - log everything\n");
    ret_str += QString(ARG_LOG_STATE_RESTRICTED" - log only SYSTEM and ERROR messages\n");
    ret_str += QString(ARG_LOG_STATE_INACTIVE" - disable log \n");
    ret_str += QString("\nDisplay options \n");
    ret_str += QString(ARG_FULLSCREEN" - is used to init the viewport in FullScreen mode\n");
    ret_str += QString(ARG_SCREEN_SIZE"WidthxHeight - used to init the viewport with the defined size \n");
    ret_str += QString("\nYou cann also use the F1 or ctrl+h key to get more infromation at runtime. \n");
    return ret_str;
    }






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





    QIODevice::OpenModeFlag open_mode = QIODevice::Truncate;

    CoreEngine w(0,mode,log_state);

    w.getLogHandler()->setLoggerState(log_state);
    w.getLogHandler()->setLoggerWriteMode(open_mode);
    /*call the startup routine*/
    w.SystemStartUp();

    w.show();
	a.exit();
    return a.exec();
}

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
	return ret_str;
}






#include <QtGui/QApplication>
#include "core/coreengine.h"
#include "core/loghandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*initialize the mode on default with the QML_UI enum
     *this is going to be changed by a parameter flag later
     */
    CoreEngine::InitMode mode = CoreEngine::WEB_UI;
    LogHandler::Log_state log_state = LogHandler::ACTIVE;

    QUrl path("");
    /*depending on the InitMode the path is set to a qml or cfg file.*/
    if(mode == CoreEngine::QML_UI)
	path = DEFAULT_QML_LAYER;
    else if (mode == CoreEngine::WEB_UI)
	path = DEFAULT_WEB_LAYER;
    CoreEngine w(0,mode,path);

    w.getLogHandler()->setLoggerState(log_state);
    /*call the startup routine*/
    w.SystemStartUp();

    w.show();

    return a.exec();
}

#include <QtGui/QApplication>
#include "core/coreengine.h"
#include "core/loghandler.h"
#include "elements/screenobject.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*initialize the mode on default with the QML_UI enum
     *this is going to be changed by a parameter flag later
     */
    CoreEngine::InitMode mode = CoreEngine::WEB_UI;
    LogHandler::Log_state log_state = LogHandler::ACTIVE;
    QIODevice::OpenModeFlag open_mode = QIODevice::Truncate;

    //qmlRegisterType<ScreenObject>("Objects", 1, 0, "ScreenObject");

    CoreEngine w(0,mode);

    w.getLogHandler()->setLoggerState(log_state);
    w.getLogHandler()->setLoggerWriteMode(open_mode);
    /*call the startup routine*/
    w.SystemStartUp();

    w.show();

    return a.exec();
}

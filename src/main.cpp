#include <QtGui/QApplication>
#include "core/coreengine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoreEngine w;
    w.show();

    return a.exec();
}

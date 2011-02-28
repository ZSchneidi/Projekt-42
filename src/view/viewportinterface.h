#ifndef VIEWPORTINTERFACE_H
#define VIEWPORTINTERFACE_H

#include <QObject>
#include "view/viewport.h"

class ViewPort;

class ViewPortInterface : public QObject
{
    Q_OBJECT

    ViewPort *parent;

public:
    explicit ViewPortInterface(ViewPort *parent = 0);

signals:

public slots:

    /*connection from qml*/
    void sendCoreAction( int action);
};

#endif // VIEWPORTINTERFACE_H

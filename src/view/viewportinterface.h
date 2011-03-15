#ifndef VIEWPORTINTERFACE_H
#define VIEWPORTINTERFACE_H

#include <QObject>
#include "view/viewport.h"
#include "core/uiobjecthandler.h"

class ViewPort;

class ViewPortInterface : public QObject
{
    Q_OBJECT

    ViewPort *parent;

    Q_PROPERTY(QUrl sublayer READ getSubLayer() CONSTANT);


public:
    explicit ViewPortInterface(ViewPort *parent = 0);

    //GETTER
    QUrl getSubLayer();

    //SETTER


signals:

public slots:

    /*connection from qml*/
    void sendCoreAction( int action);
};

#endif // VIEWPORTINTERFACE_H

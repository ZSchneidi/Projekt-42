#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QObject>

#include "global_define.h"
#include "viewportinterface.h"
#include "core/coreengine.h"

class CoreEngine;
class ViewPortInterface;

class ViewPort : public QDeclarativeView
{
    Q_OBJECT

    /**context for the QDeclarative environment*/
    QDeclarativeContext *root_context;

    CoreEngine *core;
    ViewPortInterface *interface;
    QUrl main_layer_path;

public:
    explicit ViewPort(CoreEngine *parent = 0,QUrl path = QUrl(""));

    inline CoreEngine* getCore() { return this->core; }

signals:

public slots:

};

#endif // VIEWPORT_H

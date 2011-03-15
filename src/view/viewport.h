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

    /**/
    CoreEngine *core;
    /*the interface between C++ and QML layer */
    ViewPortInterface *interface;

    QUrl main_layer_path;
    QUrl sub_layer_path;


public:
    explicit ViewPort(CoreEngine *parent = 0,QUrl path = QUrl(""));

    bool initViewPort();
    void initViewLayer(QUrl source = QUrl(""));

    void initQmlProperties();

    //GETTER
    inline CoreEngine* getCore() { return this->core; }
    inline QDeclarativeContext *getRootContext() {return this->root_context;}
    inline QUrl getSubLayerPath() { return this->sub_layer_path; }

    //SETTER
    inline void setSubLayerPath(QUrl source) { this->sub_layer_path = source; }

signals:

public slots:

};

#endif // VIEWPORT_H

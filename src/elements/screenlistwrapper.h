#ifndef SCREENLISTWRAPPER_H
#define SCREENLISTWRAPPER_H

#include <QObject>
#include "core/uiobjecthandler.h"

/** temporary not used **/
class ScreenListWrapper : public QObject
{
    Q_OBJECT

    UIObjectHandler::ScreenList *screen_list;
public:
    explicit ScreenListWrapper(QObject *parent = 0);

    Q_INVOKABLE void setModel( UIObjectHandler::ScreenList* list) {
      this->screen_list = list;

    }
    Q_INVOKABLE QVariant item(int index) {
       return QVariant::fromValue(this->screen_list->at(index));
    }



signals:

public slots:

};

#endif // SCREENLISTWRAPPER_H



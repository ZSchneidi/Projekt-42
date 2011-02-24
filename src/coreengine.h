#ifndef COREENGINE_H
#define COREENGINE_H

#include <QMainWindow>

namespace Ui {
    class CoreEngine;
}

class CoreEngine : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoreEngine(QWidget *parent = 0);
    ~CoreEngine();

private:
    Ui::CoreEngine *ui;
};

#endif // COREENGINE_H

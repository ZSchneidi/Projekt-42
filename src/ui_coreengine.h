/********************************************************************************
** Form generated from reading UI file 'coreengine.ui'
**
** Created: Thu 19. May 21:32:03 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COREENGINE_H
#define UI_COREENGINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoreEngine
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CoreEngine)
    {
        if (CoreEngine->objectName().isEmpty())
            CoreEngine->setObjectName(QString::fromUtf8("CoreEngine"));
        CoreEngine->resize(400, 300);
        menuBar = new QMenuBar(CoreEngine);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CoreEngine->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CoreEngine);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CoreEngine->addToolBar(mainToolBar);
        centralWidget = new QWidget(CoreEngine);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CoreEngine->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CoreEngine);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CoreEngine->setStatusBar(statusBar);

        retranslateUi(CoreEngine);

        QMetaObject::connectSlotsByName(CoreEngine);
    } // setupUi

    void retranslateUi(QMainWindow *CoreEngine)
    {
        CoreEngine->setWindowTitle(QApplication::translate("CoreEngine", "CoreEngine", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CoreEngine: public Ui_CoreEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COREENGINE_H

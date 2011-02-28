#-------------------------------------------------
#
# Project created by QtCreator 2011-02-24T20:09:51
#
#-------------------------------------------------

QT       += core gui declarative

TARGET = Projekt-42
TEMPLATE = app


SOURCES += main.cpp\
        core/coreengine.cpp \
    core/eventhandler.cpp \
    view/viewport.cpp \
    view/viewportinterface.cpp

HEADERS  += core/coreengine.h \
    core/eventhandler.h \
    global_define.h \
    view/viewport.h \
    view/viewportinterface.h

FORMS    += coreengine.ui

OTHER_FILES += \
    view/qml_source/MainLayer.qml \
    Project_doc.txt

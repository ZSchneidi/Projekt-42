#-------------------------------------------------
#
# Project created by QtCreator 2011-02-24T20:09:51
#
#-------------------------------------------------

QT       += core gui declarative xml

TARGET = Projekt-42
TEMPLATE = app


SOURCES += main.cpp\
        core/coreengine.cpp \
    core/eventhandler.cpp \
    view/viewport.cpp \
    view/viewportinterface.cpp \
    core/configparser.cpp \
    elements/machineconfig.cpp \
    core/loghandler.cpp \
    elements/screenobject.cpp \
    core/uiobjecthandler.cpp

HEADERS  += core/coreengine.h \
    core/eventhandler.h \
    global_define.h \
    view/viewport.h \
    view/viewportinterface.h \
    core/configparser.h \
    elements/machineconfig.h \
    core/loghandler.h \
    elements/screenobject.h \
    core/uiobjecthandler.h

FORMS    += coreengine.ui

OTHER_FILES += \
    view/qml_source/MainLayer.qml \
    Project_doc.txt \
    view/qml_source/MainWebLayer.qml \
    dev_notice.txt \
    TODO.txt

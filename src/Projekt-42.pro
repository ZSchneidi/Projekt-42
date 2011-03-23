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
    core/uiobjecthandler.cpp \
    elements/buttoncobject.cpp \
    elements/screenlistwrapper.cpp

HEADERS  += core/coreengine.h \
    core/eventhandler.h \
    global_define.h \
    view/viewport.h \
    view/viewportinterface.h \
    core/configparser.h \
    elements/machineconfig.h \
    core/loghandler.h \
    elements/screenobject.h \
    core/uiobjecthandler.h \
    elements/buttoncobject.h \
    elements/screenlistwrapper.h

FORMS    += coreengine.ui

OTHER_FILES += \
    Project_doc.txt \
    dev_notice.txt \
    TODO.txt \
    view/qml_source/WebSubLayer.qml \
    view/qml_source/QmlSubLayer.qml \
    view/qml_source/MainViewLayer.qml \
    view/qml_source/AdminPanel.qml \
    view/qml_source/KeyPad.qml \
    view/qml_source/pos_layout/PosScreen.qml\
    view/qml_source/pos_layout/Button.qml \
    view/qml_source/pos_layout/SelectionBox.qml

RESOURCES += \
    main_ressource.qrc

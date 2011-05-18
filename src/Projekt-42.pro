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
    elements/product.cpp \
    core/exception.cpp \
    view/webelementinterface.cpp \
    elements/module.cpp \
    core/eventmapper.cpp \
    elements/event.cpp \
    core/ext/eventdefinition.cpp \
    core/ext/base.cpp

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
    elements/product.h \
    core/exception.h \
    view/webelementinterface.h \
    elements/module.h \
    core/eventmapper.h \
    elements/event.h \
    core/ext/eventdefinition.h \
    core/ext/base.h

FORMS    += coreengine.ui \
    help_dialog.ui

OTHER_FILES += \
    Project_doc.txt \
    dev_notice.txt \
    TODO.txt \
    view/qml_source/WebSubLayer.qml \
    view/qml_source/QmlSubLayer.qml \
    view/qml_source/MainViewLayer.qml \
    view/qml_source/AdminPanel.qml \
    view/qml_source/pos_layout/PosScreen.qml\
    view/qml_source/pos_layout/Button.qml \
    view/qml_source/pos_layout/SelectionBox.qml \
    view/qml_source/pos_layout/MenuBar.qml \
    view/qml_source/pos_layout/MenuButton.qml \
    view/qml_source/web_elements/Screen.qml \
    view/js_source/WebUiLogic.js \
    view/qml_source/web_elements/ButtonC.qml \
    view/js_source/generic_func.js \
    view/js_source/GlobalVar.js \
    view/qml_source/elements/GenericButton.qml \
    view/qml_source/AboutDialog.qml \
    view/qml_source/HelpDialog.qml

RESOURCES += \
    main_ressource.qrc

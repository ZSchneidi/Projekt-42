#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

#include <QDebug>

#define LOG_FILE		"system_log.log"

/*define the hex representation of the button which
toggles the application fullscreen mode*/
#define TOGGLE_FULLSCREEN_BUTTON 0x41

#define DEFAULT_QML_LAYER	"view/qml_source/MainLayer.qml"
#define DEFAULT_WEB_LAYER	"view/qml_source/MainWebLayer.qml"
#define DEFAULT_WEB_CFG_DIR	"../am100002/v/cfg/"


/*define of the expected config files*/
#define MACHINE_CFG		"machine_cfg.xml"
#define MOD_CFGV		"mod_cfgv.xml"
#define OBJ_CFGV		"obj_cfgv.xml"

/*define of the known tag names*/
#define MACHINE_CFG_TAG		"machine"


/*define of the known attributes*/
//machine attributes
#define MACHINE_ATTR_ID		"id"
#define MACHINE_ATTR_AMID	"amid"
#define MACHINE_ATTR_TYPE	"typ"
#define MACHINE_ATTR_BGFILE	"bgFile"
#define MACHINE_ATTR_BGWIDTH	"bgWidth"
#define MACHINE_ATTR_BGHEIGHT	"bgHeight"
#define MACHINE_ATTR_MNR	"mnr"
#define MACHINE_ATTR_MTEL	"mtel"


/*LOG messages*/
#define SYSTEM_INIT_MSG		"Iinitialize system startup"
#define WEB_UI_INIT_MSG		"Iinitialize UI from config files"
#define QML_UI_INIT_MSG		"Iinitialize UI from qml files"
#define UNEX_CFG_MSG		"Found unexpected config file"
#define UNHA_ATT_MSG		"Found unhandled attribute \'#_1\' in \'#_2\' tag"
#define MISSING_MACH_TAG	"Missing \"" MACHINE_CFG_TAG "\" tag in " MACHINE_CFG " file"


#endif // GLOBAL_DEFINE_H

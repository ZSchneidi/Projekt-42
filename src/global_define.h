#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

#include <exception>
#include <QtCore/qtconcurrentexception.h>
#include <QDebug>

#define LOG_DIR			"log/"
#define SYSTEM_LOG_FILE		LOG_DIR"system_log.log"
#define EVENT_LOG_FILE		LOG_DIR"event_log.log"
#define CONFIG_LOG_FILE		LOG_DIR"config_log.log"

/** Core definition **/

#define SYSTEM_TIMER_INTERVAL		60000 //milliseconds

/*define the hex representation of the button which
toggles the application fullscreen mode*/
#define TOGGLE_FULLSCREEN_BUTTON 0x41

/*QML type identifiers*/
#define VIEWPORTINTERFACE						"viewportinterface"
#define ELEMENTINTERFACE						"elementinterface"

/*define the relative paths to the view layer source files*/
#define MAIN_VIEW_LAYER							"view/qml_source/MainViewLayer.qml"
#define DEFAULT_QML_LAYER						"QmlSubLayer.qml"
#define DEFAULT_WEB_LAYER						"WebSubLayer.qml"

/*define of the relative path to the machine config*/
#define DEFAULT_WEB_CFG_DIR					"config/am100002/v/cfg/"


/*define of the expected config files*/
#define MACHINE_CFG								"machine_cfg.xml"
#define MOD_CFGV									"mod_cfgv.xml"
#define OBJ_CFGV										"obj_cfgv.xml"

/*define of the known tag names*/
#define REQ_ROOT_TAG								"root"
#define MACHINE_CFG_TAG						"machine"
#define OBJECT_CFG_TAG							"object"
#define OBJECT_CFG_TYPE_ATTR				"typ"	    //used to get the type of the object


/*define of the known attributes*/
//machine attributes
#define MACHINE_ATTR_ID							"id"
#define MACHINE_ATTR_AMID					"amid"
#define MACHINE_ATTR_TYPE						"typ"
#define MACHINE_ATTR_BGFILE					"bgFile"
#define MACHINE_ATTR_BGWIDTH				"bgWidth"
#define MACHINE_ATTR_BGHEIGHT				"bgHeight"
#define MACHINE_ATTR_MNR						"mnr"
#define MACHINE_ATTR_MTEL						"mtel"

//Object types
/*these defines represents all supported  object types from the OBJ_CFGV*/
#define OBJECT_TYPE_SCREEN					"screen"
#define OBJECT_TYPE_BUTTON_C				"button_c"

//Screen obj attributes
#define SCREEN_ATTR_ID							"id"
#define SCREEN_ATTR_PARENT					"parent"
#define SCREEN_ATTR_TYPE						"typ"
#define SCREEN_ATTR_NAME						"name"
#define SCREEN_ATTR_AUX						"aux"
#define SCREEN_ATTR_TIMEOUT					"timeout"
#define SCREEN_ATTR_BGIMG					"bgImg"
#define SCREEN_ATTR_DEF						"Def"

//Button_c obj attributes
#define BUTTON_C_ATTR_ID						"id"
#define BUTTON_C_ATTR_PARENT				"parent"
#define BUTTON_C_ATTR_TYPE					"typ"
#define BUTTON_C_ATTR_NAME					"name"
#define BUTTON_C_ATTR_AUX					"aux"
#define BUTTON_C_ATTR_XPOS					"xPos"
#define BUTTON_C_ATTR_YPOS					"yPos"
#define BUTTON_C_ATTR_UPFILE				"upFile"
#define BUTTON_C_ATTR_DOFILE				"doFile"
#define BUTTON_C_ATTR_ACT_UPFILE		"actUpFile"
#define BUTTON_C_ATTR_ACT_DOFILE		"actDoFile"
#define BUTTON_C_ATTR_TEA_UPFILE			"teaUpFile"
#define BUTTON_C_ATTR_TEA_DOFILE		"teaDoFile"
#define BUTTON_C_ATTR_VISIBLE				"visible"
#define BUTTON_C_ATTR_URL_LINK			"urlLink"

/*String definitions*/
#define WARNING_TITLE							"warning"

//messages
#define NO_LOG_DIR									"no logfile dir found"

/*LOG messages*/
#define SYSTEM_INIT_MSG							"Initialize system startup"
#define WEB_UI_INIT_MSG							"Initialize UI from config files"
#define QML_UI_INIT_MSG							"Initialize UI from qml files"
#define UNEX_CFG_MSG								"Found unexpected config file"
#define UNHA_ATT_MSG								"Found unhandled attribute \'#_1\' in \'#_2\' tag"
#define UNHA_OBJ_TYPE_MSG					"Found unhandled object type \'#_1\'"
#define MISSING_MACH_TAG						"Missing \"" MACHINE_CFG_TAG "\" tag in " MACHINE_CFG " file"
#define MISSING_OBJ_TAG							"Missing \"" OBJECT_CFG_TAG "\" tag in " OBJ_CFGV " file"
#define ERROR_APP_CLOSE						"Application was closed manually"


/** QML layer definition **/
#define SYSTEM_TITLE								"StuffMates"
#define TITLE_TIME_FORMAT						"hh:mm"



#endif // GLOBAL_DEFINE_H

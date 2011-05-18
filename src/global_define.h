#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

#include <exception>
#include <QtCore/qtconcurrentexception.h>
#include <QDebug>


/**
  * The global_definition header contains all kinds of definitions
  * which are referred by the hole application.
  *
  */

#define SYS_NAME															"Projekt-42"

/* VALID STARTUP ARGUMENTS */
#define ARG_HELP															"--help"
#define ARG_WEB_UI														"--web"
#define ARG_WEB_CONFIG												"-C="
#define ARG_QML_UI														"--qml"
#define ARG_LOG_STATE_ACTIVE									"--ls_active"
#define ARG_LOG_STATE_RESTRICTED							"--ls_restrict"
#define ARG_LOG_STATE_INACTIVE								"--ls_inactive"
#define ARG_FULLSCREEN												"--fullscreen"
#define ARG_SCREEN_SIZE											"-S="

#define APP_DIR															QCoreApplication::applicationDirPath()

#define LOG_DIR															"log/"
#define SYSTEM_LOG_FILE												LOG_DIR"system_log.log"
#define EVENT_LOG_FILE												LOG_DIR"event_log.log"
#define CONFIG_LOG_FILE												LOG_DIR"config_log.log"


/** Core definition **/

#define SYSTEM_VIEWPORT_WIDTH								800
#define SYSTEM_VIEWPORT_HEIGHT								600
#define SYSTEM_TIMER_INTERVAL									60000 //milliseconds

/*define the hex representation of the button which
toggles the application fullscreen mode*/
#define TOGGLE_FULLSCREEN_BUTTON							0x41 // a
#define TERM_SYSTEM_BUTTON										0x43 // c
#define HELP_SYSTEM_BUTTON										0x48 // h

/*QML type identifiers*/
#define VIEWPORTINTERFACE											"viewportinterface"
#define ELEMENTINTERFACE											"elementinterface"

/*define the relative paths to the view layer source files*/
#define MAIN_VIEW_LAYER												"view/qml_source/MainViewLayer.qml"
#define DEFAULT_QML_LAYER											"QmlSubLayer.qml"
#define DEFAULT_WEB_LAYER											"WebSubLayer.qml"

/*define of the relative path to the machine config*/
#define DEFAULT_WEB_CFG_SUBDIR								"config/"
#define DEFAULT_CFG_DIR												"cfg"


/*define of the expected config files*/
#define MACHINE_CFG													"machine_cfg.xml"
#define MOD_CFGV														"mod_cfgv.xml"
#define OBJ_CFGV															"obj_cfgv.xml"

/*define of the known tag names*/
#define REQ_ROOT_TAG													"root"
#define MACHINE_CFG_TAG											"machine"
#define OBJECT_CFG_TAG												"object"
#define MODULE_CFG_TAG												"line"
#define OBJECT_CFG_TYPE_ATTR									"typ"	    //used to get the type of the object


/*define of the known attributes*/
//machine attributes
#define MACHINE_ATTR_ID												"id"
#define MACHINE_ATTR_AMID										"amid"
#define MACHINE_ATTR_TYPE											"typ"
#define MACHINE_ATTR_BGFILE										"bgFile"
#define MACHINE_ATTR_BGWIDTH									"bgWidth"
#define MACHINE_ATTR_BGHEIGHT									"bgHeight"
#define MACHINE_ATTR_MNR											"mnr"
#define MACHINE_ATTR_MTEL											"mtel"

#define MODULE_ATTR_MOD_ADR									"mod_adr"
#define MODULE_ATTR_SEQ											"seq"
#define MODULE_ATTR_SOURCE										"source"
#define MODULE_ATTR_EVENT_IN									"event_in"
#define MODULE_ATTR_TARGET										"target"
#define MODULE_ATTR_EVENT_OUT									"event_out"

//Object types
/*these defines represents all supported  object types from the OBJ_CFGV*/
#define OBJECT_TYPE_SCREEN										"screen"
#define OBJECT_TYPE_BUTTON_C									"button_c"
#define OBJECT_TYPE_BUTTON_T									"button_t"

//Screen obj attributes
#define SCREEN_ATTR_ID												"id"
#define SCREEN_ATTR_PARENT										"parent"
#define SCREEN_ATTR_TYPE											"typ"
#define SCREEN_ATTR_NAME											"name"
#define SCREEN_ATTR_AUX											"aux"
#define SCREEN_ATTR_TIMEOUT										"timeout"
#define SCREEN_ATTR_BGIMG										"bgImg"
#define SCREEN_ATTR_DEF											"Def"

//Button_c obj attributes
#define BUTTON_C_ATTR_ID											"id"
#define BUTTON_C_ATTR_PARENT									"parent"
#define BUTTON_C_ATTR_TYPE										"typ"
#define BUTTON_C_ATTR_NAME										"name"
#define BUTTON_C_ATTR_AUX										"aux"
#define BUTTON_C_ATTR_XPOS										"xPos"
#define BUTTON_C_ATTR_YPOS										"yPos"
#define BUTTON_C_ATTR_UPFILE									"upFile"
#define BUTTON_C_ATTR_DOFILE									"doFile"
#define BUTTON_C_ATTR_ACT_UPFILE							"actUpFile"
#define BUTTON_C_ATTR_ACT_DOFILE							"actDoFile"
#define BUTTON_C_ATTR_TEA_UPFILE								"teaUpFile"
#define BUTTON_C_ATTR_TEA_DOFILE							"teaDoFile"
#define BUTTON_C_ATTR_VISIBLE									"visible"
#define BUTTON_C_ATTR_URL_LINK								"urlLink"

//Button_t obj attributes
#define BUTTON_T_ATTR_ID											"id"
#define BUTTON_T_ATTR_PARENT									"parent"
#define BUTTON_T_ATTR_TYPE										"typ"
#define BUTTON_T_ATTR_NAME										"name"
#define BUTTON_T_ATTR_AUX										"aux"
#define BUTTON_T_ATTR_XPOS										"xPos"
#define BUTTON_T_ATTR_YPOS										"yPos"
#define BUTTON_T_ATTR_TEXT										"txt"
#define BUTTON_T_ATTR_FONTSIZE								"fontSize"
#define BUTTON_T_ATTR_XPOSTEXT								"xPosText"
#define BUTTON_T_ATTR_YPOSTEXT								"yPosText"
#define BUTTON_T_ATTR_FONTCOLOR								"fontColor"
#define BUTTON_T_ATTR_UPFILE										"upFile"
#define BUTTON_T_ATTR_DOFILE									"doFile"
#define BUTTON_T_ATTR_ACT_UPFILE								"actUpFile"
#define BUTTON_T_ATTR_ACT_DOFILE							"actDoFile"
#define BUTTON_T_ATTR_TEA_UPFILE								"teaUpFile"
#define BUTTON_T_ATTR_TEA_DOFILE								"teaDoFile"
#define BUTTON_T_ATTR_VISIBLE									"visible"
#define BUTTON_T_ATTR_FONT										"font"
#define BUTTON_T_ATTR_URL_LINK								"urlLink"
#define BUTTON_T_ATTR_FALIGN									"fAlign"

/*String definitions*/
#define WARNING_TITLE												"warning"

//messages
#define NO_LOG_DIR														"no logfile dir found"

/*LOG messages*/
#define SYSTEM_INIT_MSG												"Initialize system startup"
#define SYSTEM_ARG_MSG												"Initialize with arguments : "
#define WEB_UI_INIT_MSG												"Initialize WEB_UI"
#define QML_UI_INIT_MSG												"Initialize QML_UI"
#define UNEX_CFG_MSG													"Found unexpected config file"
#define UNHA_ATT_MSG													"Found unhandled attribute \'#_1\' in \'#_2\' tag"
#define UNHA_OBJ_TYPE_MSG										"Found unhandled object type \'#_1\'"


#define SYS_LOG_SYSTEM												"SYSTEM"
#define SYS_LOG_INFO													"INFO"
#define SYS_LOG_WARNING											"WARNING"
#define SYS_LOG_ERROR												"ERROR"

#define CONF_LOG_INFO												"INFO"
#define CONF_LOG_WARNING											"WARNING"
#define CONF_LOG_ERROR												"ERROR"

#define EVENT_LOG_PRODUCT										"PRODUCT"



#define MISSING_MACH_TAG											"Missing \"" MACHINE_CFG_TAG "\" tag in " MACHINE_CFG " file"
#define MISSING_OBJ_TAG												"Missing \"" OBJECT_CFG_TAG "\" tag in " OBJ_CFGV " file"
#define MISSING_MOD_TAG											"Missing \"" MODULE_CFG_TAG "\" tag in " MOD_CFGV " file"
#define ERROR_APP_CLOSE											"Application was closed manually"
#define RESTORE_LOG_DIR											"Restore missing log directory"

#define HELP_DIA_TITLE												"Help"
#define HELP_DIA_TEXT													SYS_NAME " help Dialog "


/** QML layer definition **/
#define SYSTEM_TITLE													"StuffMate"
#define TITLE_TIME_FORMAT											"hh:mm"
#define TITLE_DATE_FORMAT											Qt::DefaultLocaleLongDate

#endif // GLOBAL_DEFINE_H

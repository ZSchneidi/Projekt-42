#!/bin/bash

BIN_NAME="Projekt-42"
PROJ_PATH="/home/js/Development/Projekte/Projekt-42/src"
CONF_PATH="config/eins"

###########GET MACHINE CONFIG##############

AMID=100028
AJAXROOT=http://vm-jph.team.etb/amsrv/
MACH_CFG=$PROJ_PATH/$CONF_PATH/dyn/default/cfg/machine_cfg.xml

#if the machine_cfg.xml is already available do not renew the file
if [ -f $MACH_CFG ]
then
echo "Machine config is already available"
else
/usr/bin/wget -q -O $MACH_CFG $AJAXROOT/getmachinecfg.php4?amid=$AMID
fi

###########################################


#############CALL PROJECT-42 BIN###########


#this setting only shows the help dialog of projekt-42 
#ARGUMENT_SETTING="--help"

#this is a setting template can be used to start projekt-42 in qml layout
#ARGUMENT_SETTING="--qml"

#this is a setting template can be used to start projekt-42 in qml layout with fullscreen mode
#ARGUMENT_SETTING="--qml --fullscreen"

#this is a setting template can be used to start projekt-42 in web layout mode with default size
ARGUMENT_SETTING="--web"

#this is a setting template can be used to start projekt-42 in web layout with the config defined by -C mode
#ARGUMENT_SETTING="--web -C=/home/js/workspace/eins/"

echo "init script for $BIN_NAME"

echo "call $BIN_PATH $ARGUMENT_SETTING"

$PROJ_PATH/$BIN_NAME $ARGUMENT_SETTING


###########################################

#!/bin/bash

BIN_NAME="Projekt-42"
BIN_PATH="/home/js/Development/Projekte/Projekt-42/src/$BIN_NAME"

#this setting only shows the help dialog of projekt-42 
#ARGUMENT_SETTING="--help"

#this is a setting template can be used to start projekt-42 in qml layout with fullscreen mode
#ARGUMENT_SETTING="--qml --fullscreen"

#this is a setting template can be used to start projekt-42 in web layout mode with default size
ARGUMENT_SETTING="--web"

#this is a setting template can be used to start projekt-42 in web layout with the config defined by -C mode
#ARGUMENT_SETTING="--web -C=/home/js/workspace/eins/"

echo "init script for $BIN_NAME"

echo "call $BIN_PATH $ARGUMENT_SETTING"

$BIN_PATH $ARGUMENT_SETTING



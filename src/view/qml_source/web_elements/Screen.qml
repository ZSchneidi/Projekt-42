import QtQuick 1.0
import EventDefinition 0.1
import "../../js_source/generic_func.js" as Generic_func

/**
  *Representation of a screen object.
  */
Item {
    id: screen
    anchors.fill: parent
    opacity: 0

    property string background_image: ""
    property string identifier: ""
    property string screen_name: ""
    property bool default_screen: false
    property string objectType: "Screen"

    Rectangle{
		id:bgColor
		anchors.fill: parent
		color: "red"
    }

    Image {
		id: bgImage
		anchors.fill: parent
		source: background_image
    }

    function showScreen()
	{
		screen.z = 1;
	}
    function hideScreen()
	{
		screen.z = 1;
	}


	Connections{
		target: viewportinterface
		onOutEventOnTarget: {
            Generic_func.performActions(event,screen,EventDefinition);
		}
	}
}

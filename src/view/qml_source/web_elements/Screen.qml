import QtQuick 1.0

/**
  *Representation of a screen object.
  */
Item {
    id: screen
    anchors.fill: parent
    z:0

    property string background_image: ""
    property string identifier: ""
    property string screen_name: ""
    property bool default_screen: false

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

    Text {
	id: name
	text: screen_name
	anchors.centerIn: parent
	color: "white"
    }

    function showScreen()
	{
	screen.z = 1;
	}
    function hideScreen()
	{
	screen.z = 1;
	}
}

import QtQuick 1.0
import "elements"

Item {
    id: name
    property string help_text: ""

	width: 230
	height: 300

    Rectangle {
        id: rectangle1
		anchors.fill: parent
		color: "#eaeaea"
		radius: 5
		opacity: 1

		Text {
			id: text1
			height: 100
			text: help_text
			anchors.bottom: parent.bottom
			anchors.bottomMargin: 50
			anchors.right: parent.right
			anchors.rightMargin: 10
			anchors.left: parent.left
			anchors.leftMargin: 11
			wrapMode: Text.WordWrap
			font.pixelSize: 12
		}

	}

	GenericButton{
		id: ok_button
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.bottom: parent.bottom
		anchors.bottomMargin: 10
		/*access the buttons text and mouse_area property*/
		text.text: "Ok"
		mouse_area.onClicked: {
			parent.opacity = 0;
		}

	}
}



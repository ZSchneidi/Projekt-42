import QtQuick 1.0
import "elements"

Item {
    id: name
    property string help_text: ""

	width: 400
	height: 370

    Rectangle {
        id: rectangle1
		anchors.fill: parent
		color: "#eaeaea"
		radius: 5
		opacity: 1

		TextEdit {
			id: text_edit1
			x: 18
			y: 19
			width: 363
			height: 367
			text: help_text
			wrapMode: TextEdit.WordWrap
			readOnly: true
			font.pixelSize: 12
		}

	}

	GenericButton{
		id: ok_button
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.bottom: parent.bottom
		anchors.bottomMargin: 10
		/*access the buttons text and mouse_area property*/
		text: "Ok"
		mouse_area.onClicked: {
			parent.opacity = 0;
		}

	}
}



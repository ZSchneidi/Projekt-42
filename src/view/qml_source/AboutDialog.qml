import QtQuick 1.0
import "elements"

Item {
    id: name
    property string system_name: ""
    property string system_revision: ""
    property string system_author: ""
    property string system_date: ""
    property string help_text: ""

	width: 230
	height: 300

    Rectangle {
        id: rectangle1
		anchors.fill: parent
		color: "#eaeaea"
		radius: 5
		opacity: 1

		Flow {
			id: flow1
			width: 150
			height: 20
			anchors.left: parent.left
			anchors.leftMargin: 10
			anchors.top: parent.top
			anchors.topMargin: 20
			spacing: 10

			TextEdit {
				id: system
				width: 50
				height: 20
				text: "System: "
				font.bold: true
				font.pixelSize: 12
			}

			TextEdit {
				id: text_edit4
				width: 80
				height: 20
				text: system_name
				font.pixelSize: 12
			}
		}

		Flow {
			id: flow2
			width: 150
			height: 20
			spacing: 10
			anchors.top: parent.top
			anchors.topMargin: 50
			TextEdit {
				id: author
				width: 50
				height: 20
                text: "Author: "
				font.bold: true
				font.pixelSize: 12
			}

			TextEdit {
				id: text_edit5
				width: 80
				height: 20
				text: system_author
				font.pixelSize: 12
			}
			anchors.leftMargin: 10
			anchors.left: parent.left
		}

		Flow {
			id: flow3
			width: 150
			height: 20
			spacing: 10
			anchors.top: parent.top
			anchors.topMargin: 80
			TextEdit {
				id: revision
				width: 50
				height: 20
                text: "Revision: "
				font.bold: true
				font.pixelSize: 12
			}

			TextEdit {
				id: text_edit6
				width: 80
				height: 20
				text: system_revision
				font.pixelSize: 12
			}
			anchors.leftMargin: 10
			anchors.left: parent.left
		}

		Flow {
			id: flow4
			width: 150
			height: 20
			spacing: 10
			anchors.top: parent.top
			anchors.topMargin: 110
			TextEdit {
				id: date
				width: 50
				height: 20
                text: "Date: "
				font.bold: true
				font.pixelSize: 12
			}

			TextEdit {
				id: text_edit7
				width: 80
				height: 20
				text: system_date
				font.pixelSize: 12
			}
			anchors.leftMargin: 10
			anchors.left: parent.left
		}


		Rectangle {
			id: line
			height: 1
			color: "#474646"
			anchors.bottom: parent.bottom
			anchors.bottomMargin: 160
			anchors.right: parent.right
			anchors.rightMargin: 10
			anchors.left: parent.left
			anchors.leftMargin: 10
		}

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
		text: "Ok"
		mouse_area.onClicked: {
			parent.opacity = 0;
		}

	}
}



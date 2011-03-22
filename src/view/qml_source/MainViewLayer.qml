import QtQuick 1.0

Item {
    id: main_view_layer
    anchors.fill: parent
    width:  800
    height: 600

    Item {
	id: mainContent
	clip: true
	anchors.fill: parent
	Rectangle {
	    id: background
	    anchors.fill: parent

	    Rectangle {
		id: rectangle1
		color: "transparent"
		anchors.fill: parent
		z:3

		AdminPanel{
		    id: main_admin_panel
		    z:2
		}

	    }
	    Loader{
		id: mainContentLoader
		anchors.fill: parent
		source: "QmlSubLayer.qml"

		}

	}

	}

}

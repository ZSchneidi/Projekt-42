import QtQuick 1.0

/**
  * The MainViewLayer is the central qml file which dynamically loads the
  * necessary qml file depending on the InitMode
  */

Item {
    id: main_view_layer
    anchors.fill: parent

    Rectangle {
        id: background
        anchors.fill: parent

		/*The Loader is used to load the corresponding qml files depending on the InitMode*/
		Loader{
			id: sale_loader
			anchors.fill: parent
			source: viewportinterface.sublayer
		}

		/*
		AdminPanel{
			id:admin_panal
			anchors.fill: parent
		}
		*/
    }
}


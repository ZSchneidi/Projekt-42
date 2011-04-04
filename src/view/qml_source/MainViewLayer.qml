import QtQuick 1.0

Item {
    id: main_view_layer
    anchors.fill: parent

    Rectangle {
        id: background
        anchors.fill: parent

	Loader{
	    id: sale_loader
	    anchors.fill: parent
            //source: "pos_layout/PosScreen.qml"
            source: viewportinterface.sublayer
	    }

	AdminPanel{
	    id:admin_panal
	    anchors.fill: parent


	}
    }
}


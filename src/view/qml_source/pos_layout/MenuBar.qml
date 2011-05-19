import QtQuick 1.0

Item {
    property int button_width_percent: 90
    property int button_height_percent: 15


    id: menu_bar
    anchors.fill: parent

    MenuButton{
		id: cold_drinks
		button_name: "Kalte Getraenke"
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		anchors.topMargin: 10
		width: (parent.width/100)*button_width_percent
		height: (parent.height/100)*button_height_percent
		mouse_area.onClicked: {
			    loadSelectionScreen("ColdSelectionBox.qml");
				}
    }

    MenuButton{
		id: hot_drinks
		button_name: "Heisse Getraenke"
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: cold_drinks.bottom
		anchors.topMargin: 10
		width: (parent.width/100)*button_width_percent
		height: (parent.height/100)*button_height_percent
		mouse_area.onClicked: {
				loadSelectionScreen("HotSelectionBox.qml");
				}

    }

    MenuButton{
		id: snaks
		button_name: "Schnakes"
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: hot_drinks.bottom
		anchors.topMargin: 10
		width: (parent.width/100)*button_width_percent
		height: (parent.height/100)*button_height_percent
    }

    function loadSelectionScreen(source)
	{
		parent.parent.parent.select_loader.parent.loadSelectionBox(source);
	}
}




import QtQuick 1.0
import "../styles/StyleController.js" as Style


Item {
    id: pos_screen_menu

    anchors.fill: parent

    property int button_width_percent: 90
    property int button_height_percent: 15

    z: 1
    clip: true

    /* MENU BAR STATES & TRANSITIONS*/
    states: State {
        name: "visible"
        PropertyChanges { target: pos_screen_menu.parent.parent; menu_width_percent: 23}

    }
    State {
        name: "invisible"
        PropertyChanges { target: pos_screen_menu.parent.parent; menu_width_percent: 0 }
    }

    transitions: Transition {
        PropertyAnimation { properties: "menu_width_percent"; duration: 500 }
    }
    state: "visible"

    Rectangle{
        id:pos_screen_menu_background
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: Style.Color.pos_menu_background_top;
            }
            GradientStop {
                position: 1.00;
                color: Style.Color.pos_menu_background_bottom;
            }
        }
        anchors.fill: parent
    }
    Item {
        id: menu_bar
        anchors.fill: parent

        MenuButton{
            id: hot_drinks
            button_name: "Heisse Getraenke"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            width: (parent.width/100)*button_width_percent
            height: (parent.height/100)*button_height_percent
            mouse_area.onClicked: {
                loadSelectionScreen("HotSelectionBox.qml");
            }
        }

        MenuButton{
            id: cold_drinks
            button_name: "Kalte Getraenke"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: hot_drinks.bottom
            anchors.topMargin: 10
            width: (parent.width/100)*button_width_percent
            height: (parent.height/100)*button_height_percent
            mouse_area.onClicked: {
                loadSelectionScreen("ColdSelectionBox.qml");
            }
        }
        MenuButton{
            id: snaks
            button_name: "Schnakes"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: cold_drinks.bottom
            anchors.topMargin: 10
            width: (parent.width/100)*button_width_percent
            height: (parent.height/100)*button_height_percent
            mouse_area.onClicked: {
                loadSelectionScreen("SnackSelectionBox.qml");
            }
        }
    }
    Image{
        id:schadow_menu
        width: 5
        fillMode: Image.Stretch
        smooth: true
        opacity: 0.5
        source: "../img/schadow_15_col.png"
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.right
    }

    function loadSelectionScreen(source)
    {
        //state = "invisible";
        parent.parent.select_loader.parent.loadSelectionBox(source);
    }
}


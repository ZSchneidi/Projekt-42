import QtQuick 1.0
import "../styles/StyleController.js" as Style

Item{

    property int margin_percentage: 4
    property int button_width_percent: 28
    property int button_height_percent: 80


    id: snack_selection_box
    anchors.fill: parent
    opacity: 0


    states: State {
            name: "visible"
            PropertyChanges { target: snack_selection_box; opacity:1 }
        }
        State {
            name: "invisible"
            PropertyChanges { target: snack_selection_box; opacity: 0 }
        }
        transitions: Transition {
            PropertyAnimation { properties: "opacity"; duration: 500 }
        }


        Text {
            id: snack_msg
            text: "Zur Zeit sind leider keine Snacks im Angebot!"
            font.pixelSize: 24
            anchors.centerIn: parent
            font.bold: true
            color: Style.Text.title_text_color
        }


    /* JAVASCRIPT */
    function showDetailScreen(button)
    {
        button.parent.parent.parent.parent.loadDetailScreen("DetailScreen.qml",button.product);
    }

}






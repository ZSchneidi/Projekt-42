import QtQuick 1.0
import "../styles/StyleController.js" as Style

/**
  * This is a prototype of a generic button Item, that can be used in every
  * manner the user needs.
  */
Item {
    id: generic_button
    property alias mouse_area: button_mouse_area
    property alias text: button_text.text
    property alias button_background: button_back
    property int lable_size_percent: 60

    property string button_text: ""
    property int button_radius: 5
    property int button_with: 90
    property int button_height: 30

    width:  button_with
    height: button_height

	Rectangle {
		id: button_back
		anchors.fill: parent
		radius: button_radius
		gradient: Gradient {
			GradientStop {
				position: 0
				color: Style.Color.generic_button_bg_top
			}
			GradientStop {
				position: 1
				color: Style.Color.generic_button_bg_bottom
			}
		}

		Text {
			id: button_text
			anchors.centerIn: parent
			color: Style.Text.generic_button_text_color
			text: "default"
			font.bold: true
			font.pixelSize: (generic_button.height/100)*lable_size_percent;
		}

		/*shadow declaration*/
		BorderImage {
			id:shadow
			sourceSize.width: 80
			anchors.fill: button_back
			anchors { leftMargin: -5; topMargin: -8; rightMargin: -5; bottomMargin: -9 }
			border { left: 30; top: 30; right: 30; bottom: 30 }
			z:-1
			source: "../img/r_20_shadow.png"
		}

		Rectangle {
			id: highlight
			color: Style.Color.eneric_button_highlight
			radius: button_radius
			opacity: 0
			anchors.fill: parent
			z: 1
		}

		Rectangle {
			id: pressed
			color: Style.Color.eneric_button_pressed
			radius: button_radius
			opacity: 0
			anchors.fill: parent
			z: 1
		}
	}

	MouseArea{
        id:button_mouse_area
        hoverEnabled: true
        anchors.fill: parent
		onEntered: {
            highlight.opacity = 0.2
        }
        onExited: {
			highlight.opacity = 0.0
        }
		onPressed: {
			pressed.opacity = 0.2
			shadow.opacity = 0.5
        }
		onReleased: {
            pressed.opacity = 0.0
			shadow.opacity = 1.0
        }
    }
}

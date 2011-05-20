import QtQuick 1.0
import "../elements"
import "../styles/StyleController.js" as Style

Item {
    id: button_item

    property alias mouse_area: button_mouse_area
    property string button_name: "empty"
    property int button_with: 180
    property int button_height: 60
    property int lable_size_percent: 11

    width: button_with
    height: button_height

    Rectangle {
		id:button_base
		anchors.fill: parent
		radius: 20
		opacity: 1
		border.width: 0
		border.color: "#ffffff"
		z: 1
		smooth: true
		gradient:
			Gradient {
			GradientStop {
				position: 0.00;
				color: Style.Color.menu_bar_button_bg_top;
			}
			GradientStop {
				position: 0.99;
				color: Style.Color.menu_bar_button_bg_bottom;
			}
		}

		/*shadow declaration*/
		Shadow{
			id:shadow
			opacity: 0.5
		}


		Text {
			id: button_lable
			color: Style.Text.menu_bar_button_text_color;
			text: button_name
			anchors.centerIn: parent
			z: 2
			wrapMode: Text.WordWrap
			smooth: true
			//style: Text.Sunken
			//styleColor: Style.Text.menu_bar_button_text_style_color;
			font.pixelSize: (button_item.width/100)*lable_size_percent;
			font.bold: true

		}


    }

    MouseArea{
		id:button_mouse_area
		hoverEnabled: true
		anchors.fill: parent
		onEntered: {
			highlight.opacity = 0.3
		}
		onExited: {
			highlight.opacity = 0.0
		}
		onPressed: {
			pressed.opacity = 0.5
		}
		onReleased: {
			pressed.opacity = 0.0
		}
    }

    Rectangle {
		id: highlight
		color: "#e5f4fb"
		radius: 20
		opacity: 0
		anchors.fill: parent
		z: 1
    }

    Rectangle {
		id: pressed
		color: "#1f1f20"
		radius: 20
		opacity: 0
		anchors.fill: parent
		z: 1
    }
}

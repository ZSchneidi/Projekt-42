import QtQuick 1.0

Item {
    width: 800
    height: 600
    property color title_text_color: "#5c5c5c"
    property int menu_width_percent: 25
    property int title_height_percent: 20
    property int bottom_info_height_percent: 0
    property int top_info_height_percent: 0
    property int system_title_size: 90
    property int system_time_size: 60
    property int system_date_size: 20
    property int datetime_width_percent: 30
    property string title_font: "Impact"

    id: pos_screen
    /** Screen background declaration**/
    Rectangle {
		id:pos_screen_background
		gradient: Gradient {
			GradientStop {
				position: 0.00;
				color: "#bbbebd";
			}
			GradientStop {
				position: 0.48;
				color: "#cfcfcf";
			}
			GradientStop {
				position: 0.99;
				color: "#78797a";
			}
		}
		anchors.fill: parent
    }
    /** Screen title declaration **/
    Item {
		id: pos_screen_title
		anchors.top: parent.top
		anchors.right: parent.right
		anchors.left: parent.left
		height: (parent.height/100)*title_height_percent
		z: 2
		Rectangle{
			id: title_background
			anchors.fill: parent
			gradient: Gradient {
				GradientStop {
					position: 0.00;
					color: "#b3b3b3";
				}
				GradientStop {
					position: 1.00;
					color: "#dcdcdd";
				}
			}
			Image{
				id:schadow
				height: 10
				fillMode: Image.Stretch
				smooth: true
				opacity: 0.5
                source: "../img/schadow_15_bar.png"
				anchors.top: parent.bottom
				anchors.left: parent.left
				anchors.right: parent.right
			}

			Text {
				id: pos_screen_title_text
				anchors.left: parent.left
				anchors.bottom: parent.bottom
				color: title_text_color
				text: viewportinterface.system_title
				smooth: true
				font.pixelSize: (pos_screen_title.height/100)*system_title_size
				font.bold: true
				style: Text.Raised
				font.family: title_font
			}
			Item {
				id: date_time
				anchors.top: parent.top
				anchors.bottom: parent.bottom
				anchors.right: parent.right
				width: (parent.width/100)*datetime_width_percent

				Text {
					id: pos_screen_clock
					color: "#5c5c5c"
					smooth: true
					anchors.horizontalCenter: parent.horizontalCenter
					anchors.bottomMargin: (parent.height/100)*30
					font.pixelSize: (parent.height/100)*system_time_size
					font.bold: true
					style: Text.Raised
					font.family: title_font
					Connections{
						target: viewportinterface
						onSystemTimeChanged: pos_screen_clock.text = new_time
					}
				}
				Text {
					id: pos_screen_day
					smooth: true
					font.italic: false
					anchors.horizontalCenter: parent.horizontalCenter
					anchors.bottomMargin: 10
					anchors.bottom: parent.bottom
					color: title_text_color
					font.pixelSize: (parent.height/100)*system_date_size
					style: Text.Raised
					font.family: title_font
					Connections{
						target: viewportinterface
						onSystemDateChanged: pos_screen_day.text = new_date
					}
				}
			}

		}

    }

    /** Screen menu declaration **/
    Item {
		id: pos_screen_menu
		anchors.top: pos_screen_title.bottom
		anchors.left: pos_screen.left
		anchors.bottom: pos_screen.bottom
		width: (parent.width/100)*menu_width_percent
		z: 1
		Rectangle{
			id:pos_screen_menu_background
			gradient: Gradient {
				GradientStop {
					position: 0.00;
					color: "#e4e4e4";
				}
				GradientStop {
					position: 1.00;
					color: "#eeeded";
				}
			}
			anchors.fill: parent

		}

		Loader{
			id:menu_loader
			anchors.fill: parent
			source: "MenuBar.qml"
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
    }

    /** Screen selectbox declaration **/
    Item {
		id: pos_screen_select_box
		anchors.top: pos_screen_title.bottom
		anchors.left: pos_screen_menu.right
		anchors.bottom: pos_screen.bottom
		anchors.right: pos_screen.right
		Loader{
			id: selection_loader
			anchors.fill: parent
			source: "SelectionBox.qml"
		}
    }

    /** Screen top info bar declaration **/
    Item {
		id: pos_screen_top_info
		anchors.left: pos_screen_menu.right
		anchors.right: pos_screen.right
		anchors.top: pos_screen_title.bottom
		height: (parent.height/100)*top_info_height_percent
		Rectangle{
			anchors.fill: parent
			color: "lightgrey"
			opacity: 0.1
		}
    }

    /** Screen bottom info bar declaration **/
    Item {
		id: pos_screen_bottom_info
		anchors.left: pos_screen_menu.right
		anchors.right: pos_screen.right
		anchors.bottom: pos_screen.bottom
		height: (parent.height/100)*bottom_info_height_percent
		Rectangle{
			anchors.fill: parent
			color: "lightgrey"
			opacity: 0.1
		}
    }


}

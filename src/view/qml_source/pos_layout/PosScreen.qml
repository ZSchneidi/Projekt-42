import QtQuick 1.0

Item {
    width: 800
    height: 600
    property int title_height: 100
    property color title_text_color: "#5c5c5c"
    property int menu_width: 250
    property int bottom_info_height: 80
    property int top_info_height: 40

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
	height: title_height
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
		source: "E:/Dev-Labs/Projekte/Qt/Projekt-42/src/view/qml_source/img/schadow_15_bar.png"
		anchors.top: parent.bottom
		anchors.left: parent.left
		anchors.right: parent.right
	    }

	    Text {
		id: pos_screen_text
		anchors.left: parent.left
		anchors.top: parent.top
		color: title_text_color
		text: "StuffMate"
		smooth: true
		font.pixelSize: 90
		font.bold: true
		style: Text.Raised
		font.family: "Impact"
	    }
	    Text {
		id: pos_screen_clock
		color: "#5c5c5c"
		text: "13:37"
		anchors.topMargin: 0
		smooth: true
		anchors.rightMargin: 48
		anchors.right: parent.right
		anchors.top: parent.top
		font.pixelSize: 70
		font.bold: true
		style: Text.Raised
		font.family: "Impact"
	    }
	    Text {
		id: pos_screen_day
		text: "Mittwoch, 3. Mai 2011"
		smooth: true
		font.italic: false
		anchors.topMargin: 65
		anchors.rightMargin: 15
		anchors.right: parent.right
		anchors.top: parent.top
		color: title_text_color
		font.pixelSize: 25
		style: Text.Raised
		font.family: "Impact"
	    }
	}

    }

    /** Screen menu declaration **/
    Item {
	id: pos_screen_menu
	anchors.top: pos_screen_title.bottom
	anchors.left: pos_screen.left
	anchors.bottom: pos_screen.bottom
	width: menu_width
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
	anchors.bottom: pos_screen_bottom_info.top
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
	height: top_info_height
	Rectangle{
	    anchors.fill: parent
	    color: "lightgrey"
	}
    }

    /** Screen bottom info bar declaration **/
    Item {
	id: pos_screen_bottom_info
	anchors.left: pos_screen_menu.right
	anchors.right: pos_screen.right
	anchors.bottom: pos_screen.bottom
	height: bottom_info_height
	Rectangle{
	    anchors.fill: parent
	    color: "lightgrey"
	}
    }


}

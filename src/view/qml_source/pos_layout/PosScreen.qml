import QtQuick 1.0

Item {

    property int title_height: 100
    property color title_text_color: "#5c5c5c"

    id: pos_screen
    //Screen background
    Rectangle {
	id:pos_screen_background
	anchors.fill: parent
	gradient: Gradient {
	     GradientStop {
		 position: 0
		 color: "#4b3c12"
	     }

	     GradientStop {
		 position: 0.47
		 color: "#7a6324"
	     }

	     GradientStop {
		 position: 0.99
		 color: "#6b5434"
	     }
	 }
    }
    Item {
	id: pos_screen_title
	anchors.top: parent.top
	anchors.right: parent.right
	anchors.left: parent.left
	height: title_height
	clip: true
	Rectangle{
	    id: title_background
	    color: "black"
	    anchors.fill: parent
	    Text {
		id: pos_screen_text
		anchors.left: parent.left
		anchors.top: parent.top
		color: title_text_color
		text: "StuffMate"
		font.pixelSize: 90
		font.bold: true
		style: Text.Raised
		font.family: "Impact"
	    }
	    Text {
		id: pos_screen_clock
  color: "#5c5c5c"
		text: "13:37"
		anchors.rightMargin: 50
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


}

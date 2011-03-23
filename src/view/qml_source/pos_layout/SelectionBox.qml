import QtQuick 1.0


Item{

    property int margin_percentage: 4
    property int button_width_percent: 28
    property int button_height_percent: 80

    id: selection_box
    anchors.fill: parent

    width: 800
    height: 600

    Item {
	id: first_row
	anchors.top: parent.top
	anchors.left: parent.left
	anchors.right: parent.right
	height: (parent.height/100)*50

	Button{
	    id: button1
	    x: 58
	    y: 74
	    button_name: "Kaffe"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: parent.left
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    //anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}

	Button{
	    id: button2
	    x: 58
	    y: 74
	    button_name: "Kaffe schwarz"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: button1.right
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}

	Button{
	    id: button3
	    x: 58
	    y: 74
	    button_name: "Kaffe schwarz"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: button2.right
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}

    }

    Item {
	id: second_row
	anchors.top: first_row.bottom
	anchors.bottom: parent.bottom
	anchors.left: parent.left
	anchors.right: parent.right


	Button{
	    id: button4
	    x: 58
	    y: 74
	    button_name: "Kaffe"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: parent.left
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    //anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}

	Button{
	    id: button5
	    x: 58
	    y: 74
	    button_name: "Kaffe schwarz"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: button4.right
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}

	Button{
	    id: button6
	    x: 58
	    y: 74
	    button_name: "Kaffe schwarz"
	    anchors.verticalCenter: parent.verticalCenter
	    anchors.left: button5.right
	    anchors.leftMargin: (parent.width/100)*margin_percentage
	    anchors.topMargin: (parent.height/100)*margin_percentage
	    button_with: (parent.width/100)*button_width_percent
	    button_height: (parent.height/100)*button_height_percent

	}
    }

}

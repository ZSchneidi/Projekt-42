import QtQuick 1.0


Item{
    id: selection_box
    anchors.fill: parent

    width: 800
    height: 600

    Button{
	id: button1
	x: 58
	y: 74
	button_name: "Kaffe"

    }

    Button {
	id: button2
	x: 58
	y: 230
	button_name: "Kaffe Schwarz"
    }

    Button {
	id: button3
	x: 208
	y: 74
    }

    Button {
	id: button4
	x: 208
	y: 230
    }

    Button {
	id: button5
	x: 358
	y: 230
    }

    Button {
	id: button6
	x: 358
	y: 74
    }
}

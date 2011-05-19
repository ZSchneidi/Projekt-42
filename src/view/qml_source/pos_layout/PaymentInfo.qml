import QtQuick 1.0
import "../elements"

Item {
    id: payment_info
    anchors.fill: parent

	property string price_to_pay: "0.00"
	property string paid_value: "0.00"
	property string unit: "€"

	/* SCREEN STATES & TRANSITIONS*/
    states: State {
		name: "visible"
		PropertyChanges { target: payment_info.parent.parent.parent; bottom_info_height_percent: 10 }

	}
	State {
		name: "invisible"
		PropertyChanges { target: payment_info.parent.parent.parent; bottom_info_height_percent: 0 }
	}

	transitions: Transition {
		PropertyAnimation { properties: "bottom_info_height_percent"; duration: 300 }
	}

	Text {
		id: price
		text: "Preis: "+price_to_pay+" "+unit
		textFormat: Text.RichText
		color: "#383737"
		font.bold: true
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		anchors.topMargin: parent.height/100*10
		font.pixelSize: (parent.height/100)*40;
	}
	Text {
		id: paid
		text: "Bezahlt: "+paid_value+" "+unit
		color: "#383737"
		font.bold: true
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		anchors.topMargin: parent.height/100*60
		font.pixelSize: (parent.height/100)*20;
	}

    GenericButton{
		id: back_button
		text: "Zurück"
		button_radius: 2
		anchors.verticalCenter: parent.verticalCenter
		anchors.left: parent.left
		anchors.leftMargin: 20
		height: parent.height/100*80
		lable_size_percent:40
		mouse_area.onClicked: {
			goBack();
		}
    }

	GenericButton{
		id: buy_button
		text: "Kaufen"
		button_radius: 2
		anchors.verticalCenter: parent.verticalCenter
		anchors.right: parent.right
		anchors.rightMargin: 20
		height: parent.height/100*80
		lable_size_percent: 40
		mouse_area.onClicked: {
			buy();
		}
    }

	/* JAVASCRIPT */

	function goBack()
	{
	//payment_info.parent.item.state = "invisible";
	//console.log(payment_info.parent.parent.parent.select_loader.parent.);
	payment_info.parent.parent.parent.select_loader.parent.loadSelectionBox(payment_info.parent.parent.parent.current_select_box);


	}

	function buy()
	{
	payment_info.parent.item.state = "invisible";

	}




}




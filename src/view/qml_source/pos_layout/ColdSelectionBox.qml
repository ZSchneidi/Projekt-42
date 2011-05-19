import QtQuick 1.0

Item{

    property int margin_percentage: 4
    property int button_width_percent: 28
    property int button_height_percent: 80


    id: cold_selection_box
    anchors.fill: parent
    opacity: 0

    states: State {
			name: "visible"
			PropertyChanges { target: cold_selection_box; opacity:1 }
		}
		State {
			name: "invisible"
			PropertyChanges { target: cold_selection_box; opacity: 0 }
		}

		transitions: Transition {
			PropertyAnimation { properties: "opacity"; duration: 500 }
		}

    Item {
		id: first_row
		anchors.top: parent.top
		anchors.left: parent.left
		anchors.right: parent.right
		height: (parent.height/100)*50

		Button{
			id: button1
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: parent.left
			anchors.leftMargin: (parent.width/100)*margin_percentage
			//anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
			product.productCode: 33214
			product.productName: "Wasser"

		}

		Button{
			id: button2
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button1.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
			product.productCode: 32234
			product.productName: "Eis Tee"

			mouse_area.onClicked: {
				showDetailScreen(button2);
			}
		}

		Button{
			id: button3
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button2.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent

			product.productCode: 43321
			product.productName: "Kalter Kaffe"
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
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: parent.left
			anchors.leftMargin: (parent.width/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
			product.productCode: 43321
			product.productName: "Wurstwasser"
		}

		Button{
			id: button5
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button4.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
			product.productCode: 43321
			product.productName: "Bier"
		}

		Button{
			id: button6
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button5.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
			product.productCode: 43321
			product.productName: "Korn"
		}
    }


	/* JAVASCRIPT */
	function showDetailScreen(button)
	{

		button.parent.parent.parent.parent.loadDetailScreen("DetailScreen.qml",button.product);
	}

}






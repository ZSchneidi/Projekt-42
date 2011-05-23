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
            product.productCode: 100156
            product.productPrice: 1.10
            product.productName: "Cola"
            product.productDesc: "Coka Cola 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/cola.png"
            mouse_area.onClicked: {
                showDetailScreen(button1);
            }

		}

		Button{
			id: button2
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button1.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
			button_height: (parent.height/100)*button_height_percent
            product.productCode: 100157
            product.productPrice: 1.10
            product.productName: "Red Bull"
            product.productDesc: "Energy Drink 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/red-bull.png"
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
            product.productCode: 100158
            product.productPrice: 1.10
            product.productName: "Sprite"
            product.productDesc: "Erfrischungsgetränk 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/sprite.png"
            mouse_area.onClicked: {
                showDetailScreen(button3);
            }
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
            product.productCode: 100159
            product.productPrice: 1.10
            product.productName: "Duff Bier"
            product.productDesc: "Bier 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/Duff1.png"
            mouse_area.onClicked: {
                showDetailScreen(button4);
            }
		}

		Button{
			id: button5
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button4.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
            button_height: (parent.height/100)*button_height_percent
            product.productCode: 100160
            product.productPrice: 1.10
            product.productName: "Coke Zero"
            product.productDesc: "Coca Cola ohne Zucker 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/coke-zero.png"
            mouse_area.onClicked: {
                showDetailScreen(button5);
            }
		}

		Button{
			id: button6
			anchors.verticalCenter: parent.verticalCenter
			anchors.left: button5.right
			anchors.leftMargin: (parent.width/100)*margin_percentage
			anchors.topMargin: (parent.height/100)*margin_percentage
			button_with: (parent.width/100)*button_width_percent
            button_height: (parent.height/100)*button_height_percent
            product.productCode: 100161
            product.productPrice: 1.10
            product.productName: "Fanta"
            product.productDesc: "Orangengetränk 0,33 Ltr."
            product.productIngred: "-"
            product.productImage: "../img/fanta.png"
            mouse_area.onClicked: {
                showDetailScreen(button6);
            }
		}
    }


	/* JAVASCRIPT */
	function showDetailScreen(button)
	{

		button.parent.parent.parent.parent.loadDetailScreen("DetailScreen.qml",button.product);
	}

}






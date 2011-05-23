import QtQuick 1.0

Item{

    property int margin_percentage: 4
    property int button_width_percent: 28
    property int button_height_percent: 80


    id: hot_selection_box
    anchors.fill: parent
    opacity: 0


    states: State {
			name: "visible"
			PropertyChanges { target: hot_selection_box; opacity:1 }
		}
		State {
			name: "invisible"
			PropertyChanges { target: hot_selection_box; opacity: 0 }
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
			/* Produkt definition */
			product.productCode: 100253
			product.productPrice: 0.80
			product.productName: "Kaffe"
			product.productDesc: "Einfach Schwarzer Kaffe"
			product.productIngred: "Bohnen\nWasser"
            product.productImage: "../img/Coffee.png"
            product.isMeasurable: true
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
			/* Produkt definition */
			product.productCode: 100254
			product.productPrice: 1.00
			product.productName: "Cappuccino"
            product.productDesc: "Espresso, heiße Milch und heißer Milchschaum"
            product.productIngred: "Robusta-Bohnen\nMilchschaum"
            product.productImage: "../img/Cappuccino.png"
            product.isMeasurable: true
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
			/* Produkt definition */
			product.productCode: 100255
			product.productPrice: 1.20
            product.productName: "Latte macchiato"
            product.productDesc: "Warmgetränk aus Milch und Espresso"
            product.productIngred: "-"
            product.productImage: "../img/latte_macchiato.png"
            product.isMeasurable: true
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
			/* Produkt definition */
			product.productCode: 100256
			product.productPrice: 1.20
			product.productName: "Cafe au Lait"
			product.productDesc: "Milchkaffee ist ein Kaffee mit einem hohen Anteil Milch oder Milchschaum."
			product.productIngred: "-"
            product.productImage: "../img/Coffee.png"
            product.isMeasurable: true
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
			/* Produkt definition */
			product.productCode: 100257
			product.productPrice: 0.90
			product.productName: "Schokolade"
			product.productDesc: "Kakaohaltiges Getränk"
			product.productIngred: "Kakaopulver\nWasser"
            product.productImage: "../img/hot-chocolate.png"
            product.isMeasurable: true
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
			/* Produkt definition */
			product.productCode: 100258
			product.productPrice: 1.10
			product.productName: "Cafe Creme"
			product.productDesc: "-"
			product.productIngred: "-"
            product.productImage: "../img/Coffee.png"
            product.isMeasurable: true
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






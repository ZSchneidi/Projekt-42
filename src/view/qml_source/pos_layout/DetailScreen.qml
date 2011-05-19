import QtQuick 1.0
import Product 0.1
import "../elements"

Item{
	id:detail_screen
    anchors.fill: parent

	width: 800
	height: 600

    property alias product: m_product
    property alias product_name:  m_product_name.text
    property alias product_desc:  m_product_desc.text
    property alias product_price:  m_product.productPrice
    property alias product_code:  m_product.productCode


    opacity: 1

	/* SCREEN STATES & TRANSITIONS*/
    states: State {
		name: "visible"
		PropertyChanges { target: detail_screen; opacity:1 }

	}
	State {
		name: "invisible"
		PropertyChanges { target: detail_screen; opacity: 0 }
	}

	transitions: Transition {
		PropertyAnimation { properties: "opacity"; duration: 500 }
	}

	Product{
		id: m_product
		productName: m_product_name.text

    }

    Rectangle {
        id: rectangle1
        color: "#888a8d"
        radius: 20
        opacity: 1
        anchors.rightMargin: 50
        anchors.leftMargin: 50
        anchors.bottomMargin: 50
		anchors.topMargin: (parent.height/100)*40
        anchors.fill: parent
		Shadow{
			opacity: 0.5
		}

    }

    Text {
        id: m_product_name
        text: "text"
        font.bold: true
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.left: parent.left
        anchors.leftMargin: 50
        font.pixelSize: 40
    }

    Text {
        id: m_product_desc
        y: 6
        text: "text"
        font.pixelSize: 22
        anchors.top: parent.top
        anchors.topMargin: 90
        font.bold: true
        anchors.leftMargin: 50
        anchors.left: parent.left
    }



    Component.onCompleted: {
		//console.log(product.productName);
	}
}

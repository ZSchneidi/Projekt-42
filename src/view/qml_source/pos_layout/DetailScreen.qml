import QtQuick 1.0
import Product 0.1
import "../elements"
import "../styles/StyleController.js" as Style

Item{
	id:detail_screen
    anchors.fill: parent

	width: 800
	height: 600

    property alias product: m_product
    property alias product_name:  m_product_name.text
    property alias product_desc:  m_product_desc.text
    property alias product_ingred:  m_product_ingred.text
    property alias product_price:  m_product.productPrice
    property alias product_code:  m_product.productCode
    property alias product_image:  product_img.source

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
    }
    Rectangle {
        id: variation_box
        color: Style.Color.detail_screen_variation_box_bg
        radius: 20
        height: (parent.height/100) *40
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.rightMargin: 50
        anchors.leftMargin: 50
        anchors.bottomMargin: 50
		Shadow{
			opacity: 0.5
		}
    }
    Item {
        id: product_image_box
        width: height
        anchors.bottom: variation_box.top
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 40
		Image {
			id: product_img
			anchors.fill: parent
			source: ""
		}
    }
    Item {
        id: text_area
        clip: true
        anchors.bottom: variation_box.top
        anchors.bottomMargin: 10
        anchors.right: product_image_box.left
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 40
		Text {
			id: m_product_ingred
			y: 6
			text: "-"
			anchors.right: parent.right
			font.pixelSize:  (parent.height/100) * 10
			anchors.top: ingred_head.bottom
			anchors.topMargin: 5
			anchors.left: parent.left
		}
		Text {
			id: ingred_head
			y: 6
			text: "Zutaten:"
			anchors.right: parent.right
			font.pixelSize:  (parent.height/100) * 10
			anchors.top: m_product_desc.bottom
			anchors.topMargin: 5
			font.bold: true
			anchors.left: parent.left
		}
		Text {
			id: m_product_desc
			text: "-"
			wrapMode: Text.WordWrap
			font.pixelSize: (parent.height/100) * 10
			anchors.top: m_product_name.bottom
			anchors.topMargin: 10
			font.bold: true
			anchors.left: parent.left
			anchors.right: parent.right

		}
		Text {
			id: m_product_name
			text: "-"
			anchors.right: parent.right
			font.bold: true
			anchors.top: parent.top
			anchors.left: parent.left
			font.pixelSize: (parent.height/100) * 30
		}
    }


	/* JAVASCRIPT */

	function initProductData(product)
	{
		if(product.productName !== "")
			product_name = product.productName;
		if(product.productDesc !== "")
			product_desc = product.productDesc;
		if(product.productIngred !== "")
			product_ingred = product.productIngred;
		if(product.productPrice > 0.0)
			product_price = product.productPrice;
		if(product.productCode !== "")
			product_code = product.productCode;
		if(product.productCode !== "")
			product_image = product.productImage;
		showPriceInfo(product);
	}

	function showPriceInfo(product)
	{

		parent.parent.parent.bottom_info_loader.source = "PaymentInfo.qml";
		parent.parent.parent.bottom_info_loader.item.state = "visible";
		parent.parent.parent.bottom_info_loader.item.setPriceToPay(product);
	}
}


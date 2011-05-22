import QtQuick 1.0
import Product 0.1
import "../elements"
import "../styles/StyleController.js" as Style
import "../../js_source/GlobalVar.js" as GlobalVar

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
    property alias product_milk_value:  milk_value.value
    property alias product_sugar_value:  sugar_value.value

    property int dezimal_digits: 2
    property real milk_price: GlobalVar.milk_price
    property real sugar_price: GlobalVar.sugar_price
    property real additional_cost: 0

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

  Text {
      id: text1
      x: 525
      y: 65
      text: "+ "+(milk_price*product_milk_value).toFixed(dezimal_digits).toString().replace(".",Style.String.digit_seperator)+" "+Style.String.unit
      anchors.right: parent.right
      anchors.rightMargin: 40
      anchors.bottom: line.top
      anchors.bottomMargin: 50
      font.bold: false
      font.pixelSize: 25
  }

  Text {
      id: text2
      x: 591
      text: "("+milk_price.toFixed(dezimal_digits).toString().replace(".",Style.String.digit_seperator)+" "+Style.String.unit+"/ Einheit)"

      anchors.top: text1.bottom
      anchors.topMargin: 10
      anchors.right: parent.right
      anchors.rightMargin: 40
      font.pixelSize: 12
  }

  Rectangle {
      id: line
      x: 54
      y: 129
      width: parent.width-60
      height: 2
      color: "#1e1e1e"
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.verticalCenter: parent.verticalCenter
  }

  Text {
      id: text3
      x: 523
      text: "+ "+(sugar_price*product_sugar_value).toFixed(dezimal_digits).toString().replace(".",Style.String.digit_seperator)+" "+Style.String.unit
      anchors.top: line.bottom
      anchors.topMargin: 30
      font.pixelSize: 25
      anchors.rightMargin: 40
      font.bold: false
      anchors.right: parent.right
  }

  Text {
      id: text4
      x: 589
      text: "("+sugar_price.toFixed(dezimal_digits).toString().replace(".",Style.String.digit_seperator)+" "+Style.String.unit+"/ Einheit)"
      anchors.top: text3.bottom
      anchors.topMargin: 10
      font.pixelSize: 12
      anchors.rightMargin: 40
      anchors.right: parent.right
  }

  Text {
      id: text5
      y: 88
      text: "Milch"
      z: 2
      anchors.left: parent.left
      anchors.leftMargin: 30
      anchors.bottom: line.top
      anchors.bottomMargin: 10
      font.pixelSize: 15
  }

  Text {
      id: text6
      text: "Milch"
      z: 2
      anchors.bottom: parent.bottom
      anchors.bottomMargin: 0
      font.pixelSize: 15
      anchors.leftMargin: 30
      anchors.left: parent.left
  }

  Image {
      id: image1
      x: 56
      y: 9
      width: 100
      height: 100
      anchors.left: parent.left
      anchors.leftMargin: 50
      anchors.bottom: line.top
      anchors.bottomMargin: 10
      fillMode: Image.PreserveAspectFit
      source: "../img/kaffeesahne.jpg"
  }

  Image {
      id: image2
      x: 59
      width: 100
      height: 100
      anchors.bottom: parent.bottom
      anchors.bottomMargin: 10
      source: "../img/sugar.jpg"
      fillMode: Image.PreserveAspectFit
      anchors.leftMargin: 50
      anchors.left: parent.left
  }

  Measure {
      id: milk_value
      anchors.bottom: line.top
      anchors.bottomMargin: 20
      anchors.top: parent.top
      anchors.topMargin: 20
      anchors.left: parent.left
      anchors.leftMargin: 160
      anchors.right: parent.right
      anchors.rightMargin: 160
      onValueChanged: {
          additional_cost = (milk_price*product_milk_value)+(sugar_price*product_sugar_value);
          updatePriceInfo(additional_cost);

      }
  }

  Measure {
      id: sugar_value
      anchors.bottom: parent.bottom
      anchors.top: line.bottom
      anchors.left: parent.left
      anchors.right: parent.right
      anchors.topMargin: 20
      anchors.rightMargin: 160
      anchors.bottomMargin: 20
      anchors.leftMargin: 160
      onValueChanged: {
          additional_cost = (milk_price*product_milk_value)+(sugar_price*product_sugar_value);
          updatePriceInfo(additional_cost);
      }
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
            fillMode: Image.PreserveAspectFit
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
            font.pixelSize: (parent.height/100) * 23
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
    function updatePriceInfo(price)
    {
        parent.parent.parent.bottom_info_loader.item.updatePriceToPay(price);
    }
}


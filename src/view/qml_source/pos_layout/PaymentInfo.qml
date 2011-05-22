import QtQuick 1.0
import Product 0.1
import "../elements"
import "../styles/StyleController.js" as Style
import "../../js_source/generic_func.js" as GenericJs
import Base 0.1

Item {
    id: payment_info
    anchors.fill: parent

	property int dezimal_digits: 2
    property string unit: Style.String.unit
    property string digit_seperator: Style.String.digit_seperator
    property real price_to_pay: 0.0
    property real base_price_to_pay: 0.0
	property string paid_value: "0"+digit_seperator+"00"

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
        text: "Preis: "+price_to_pay.toFixed(dezimal_digits).toString().replace(".",digit_seperator)+" "+unit
		textFormat: Text.RichText
		color:  Style.Text.default_text_color
		font.bold: true
		anchors.horizontalCenter: parent.horizontalCenter
		anchors.top: parent.top
		anchors.topMargin: parent.height/100*10
		font.pixelSize: (parent.height/100)*40;
	}
	Text {
		id: paid
		text: "Bezahlt: "+paid_value+" "+unit
		color: Style.Text.default_text_color
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
        button_with: 120
		anchors.verticalCenter: parent.verticalCenter
		anchors.left: parent.left
		anchors.leftMargin: 20
		height: parent.height/100*80
		lable_size_percent:40
		mouse_area.onClicked: {
            viewportinterface.sendProductAction(temp_product,Base.Canceled);
			goBack();
		}
    }

	GenericButton{
		id: buy_button
		text: "Kaufen"
		button_radius: 2
        button_with: 120
		anchors.verticalCenter: parent.verticalCenter
		anchors.right: parent.right
		anchors.rightMargin: 20
		height: parent.height/100*80
		lable_size_percent: 40
        mouse_area.onClicked: {
            viewportinterface.sendProductAction(temp_product,Base.Bought);
			buy();
		}
    }

	Product{
		id: temp_product
	}

	/* JAVASCRIPT */


	function goBack()
	{
	payment_info.parent.parent.parent.select_loader.parent.loadSelectionBox(payment_info.parent.parent.parent.current_select_box);
	}

	function buy()
	{
	payment_info.parent.item.state = "invisible";
    payment_info.parent.parent.parent.pos_menu_bar.state = "invisible";
    payment_info.parent.parent.parent.select_loader.parent.loadServScreen(temp_product);
	}

	function setPriceToPay(product)
	{
        GenericJs.initProductObject(product,temp_product);
        price_to_pay = temp_product.productPrice;
        base_price_to_pay = price_to_pay;

	}
    function updatePriceToPay(price)
    {
        console.log("new price "+price);
        price_to_pay = base_price_to_pay+price;
    }


}




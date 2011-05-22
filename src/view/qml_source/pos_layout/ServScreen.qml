import QtQuick 1.0
import "../elements"
import "../styles/StyleController.js" as Style
import "../../js_source/generic_func.js" as GenericJs
import Product 0.1
import Base 0.1

Item {
    id: server_screen
    anchors.fill: parent
    property int leve_timeout: 2000

    width: 800
    height: 600

    /* MENU BAR STATES & TRANSITIONS*/
    states: State {
        name: "finished"
        PropertyChanges { target: finished_text; opacity: 1}
        PropertyChanges { target: progress; opacity: 0}

    }
    transitions: Transition {
        PropertyAnimation { properties: "opacity"; duration: 300 }
    }

    onStateChanged: {
        if(state == "finished")
        {
            leave_timer.start();
        }
    }

    Timer {
            id: leave_timer
             interval: leve_timeout; running: false; repeat: false
             onTriggered: returnToPOS();
         }

	Text {
		id: buy
		text: "Produktausgabe"
		color: Style.Text.default_text_color
		horizontalAlignment: Text.AlignHCenter
		font.pointSize: 20
		font.bold: true
		anchors.top: parent.top
		anchors.topMargin: 80
		anchors.horizontalCenter: parent.horizontalCenter
	}
	Text {
		id: served_product
		text: "-"
		color: Style.Text.default_text_color
		horizontalAlignment: Text.AlignHCenter
		font.pointSize: 20
		font.bold: true
		anchors.top: buy.bottom
		anchors.topMargin: 10
		anchors.horizontalCenter: parent.horizontalCenter
	}

	Item {
		id: progress
		anchors.verticalCenter: parent.verticalCenter
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.leftMargin: 50
		anchors.rightMargin: 50
		height: 40

		ProgressBar {

            /*the progressbar doesn't have any background and was implemented just for visual integrity*/
			anchors.fill: parent
            NumberAnimation on value { duration: 3000 ; from: 0; to: 100;  }
            ColorAnimation on color { duration: 3000; from: Style.Color.serv_progress_color_top_start; to: Style.Color.serv_progress_color_top_end;  }
            ColorAnimation on secondColor { duration: 3000; from: Style.Color.serv_progress_color_bottom_start; to: Style.Color.serv_progress_color_bottom_end;  }
            onValueChanged:
                if(value == maximum)
                    {
                    /*the product served events will later emited by the backend*/
                    viewportinterface.sendProductAction(temp_product,Base.Served);
                    server_screen.state = "finished";
                    }
		}


	}

    Text {
        id: finished_text
        text: "Ihr Produkt ist fertig"
        color: Style.Text.default_text_color
        opacity: 0
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 20
        font.bold: true
        anchors.centerIn: parent
    }

    Product{
        id:temp_product
    }

    function setProduct(product)
    {
        GenericJs.initProductObject(product,temp_product);
        served_product.text = temp_product.productName;
	}

    function returnToPOS()
    {
        parent.parent.returnToSelection();

    }
}

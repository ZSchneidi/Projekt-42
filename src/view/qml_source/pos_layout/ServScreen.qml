import QtQuick 1.0
import "../elements"
import "../styles/StyleController.js" as Style

Item {
    id: server_screen
    anchors.fill: parent

    width: 800
    height: 600

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

			anchors.fill: parent
			NumberAnimation on value { duration: 3000 ; from: 0; to: 100;  }
			ColorAnimation on color { duration: 3000; from: Style.Color.serv_progress_color_top_start; to: Style.Color.serv_progress_color_top_end;  }
			ColorAnimation on secondColor { duration: 3000; from: Style.Color.serv_progress_color_bottom_start; to: Style.Color.serv_progress_color_bottom_end;  }
		}
	}

	function setProduct(productName)
	{
		served_product.text = productName;
	}
}

import QtQuick 1.0
import Product 0.1
import "../elements"
import "../styles/StyleController.js" as Style
import Base 0.1


Item {
    id: button_item
    property alias mouse_area: button_mouse_area
    property alias button_name: product.productName
    property string button_image: product.productImage
    property int button_with: 130
    property int button_height: 140
    property int lable_size_percent: 10

    property alias product: product

    width: button_with
    height: button_height

    Rectangle {
        id:button_base
		anchors.fill: parent
        radius: 20
        opacity: 1
        border.width: 0
        border.color: Style.Color.product_button_border
		z: 1
        smooth: true
        gradient:
            Gradient {
            GradientStop {
                position: 0
                color: Style.Color.product_button_bg_top
            }

            GradientStop {
                position: 0.99
                color: Style.Color.product_button_bg_bottom
			}
		}
		/*shadow declaration*/
		Shadow{
			id:shadow
		}

		/*this is the buttons lable*/
		Text {
            id: button_label
			y: 11
			text: button_name
			color: Style.Text.product_button_text_color
			anchors.right: parent.right
			anchors.rightMargin: 5
			anchors.left: parent.left
			anchors.leftMargin: 5
			anchors.bottom: parent.bottom
			anchors.bottomMargin: 10
			z: 2
			wrapMode: Text.WordWrap
			smooth: true
            style: Text.Sunken
            verticalAlignment: Text.AlignTop
			horizontalAlignment: Text.AlignHCenter
			font.pixelSize: (button_item.height/100)*lable_size_percent;

        }
        Item {
            id: picture
			anchors.fill: parent
            anchors.bottomMargin: (parent.height/100)*25

            Rectangle {
                id: rectangle1
                radius: 20
				anchors.fill: parent
				anchors.bottomMargin: 0

				border.width: 0
				border.color: Style.Color.product_button_innerborder
                gradient: Gradient {
                    GradientStop {
                        position: 0
                        color: Style.Color.product_button_img_bg_top
                    }

                    GradientStop {
                        position: 0.96
                        color: Style.Color.product_button_img_bg_bottom
                    }
                }
                clip: true
                opacity: 1
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                anchors.topMargin: 10

				/*Product image*/
                Image {
                    id: image1
                    z: 1
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    anchors.topMargin: 5
					source: button_image
                }
            }
        }
    }

    /*product definition is used to link product information to a Button*/
    Product{
		id:product
		productName: ""
		productCode: 0

    }

    MouseArea{
        id:button_mouse_area
        hoverEnabled: true
        anchors.fill: parent
		onEntered: {
            highlight.opacity = 0.3
        }
        onExited: {
			highlight.opacity = 0.0
        }
        onClicked: {
            viewportinterface.sendProductAction(product,Base.Selected)
        }
        onPressed: {
			pressed.opacity = 0.3
			shadow.opacity = 0.5
        }
		onReleased: {
            pressed.opacity = 0.0
			shadow.opacity = 1.0
        }
    }
    Rectangle {
        id: highlight
        color: Style.Color.product_button_highlight
        radius: 20
        opacity: 0
        anchors.fill: parent
        z: 1
    }
    Rectangle {
        id: pressed
        color: Style.Color.product_button_pressed
        radius: 20
        opacity: 0
        anchors.fill: parent
        z: 1
    }
}

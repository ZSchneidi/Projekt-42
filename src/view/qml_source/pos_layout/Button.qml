import QtQuick 1.0
Item {
    id: button_item
    property string button_name: "empty"
    property int button_with: 130
    property int button_height: 140


    width: button_with
    height: button_height

    Rectangle {
        id:button_base
        anchors.fill: parent
        radius: 20
        opacity: 1
        border.width: 0
        border.color: "#ffffff"
        z: 1
        rotation: 0
        scale: 1
        smooth: true
        gradient:
            Gradient {
            GradientStop {
                position: 0
                color: "#a3a7a8"
            }

            GradientStop {
                position: 0.99
                color: "#212b31"
	    }
	}
	/*shadow declaration*/
	BorderImage {
	    anchors.fill: button_base
	    anchors { leftMargin: -10; topMargin: -10; rightMargin: -10; bottomMargin: -10 }
	    border { left: 30; top: 30; right: 30; bottom: 30 }
	    horizontalTileMode: BorderImage.Stretch
	    verticalTileMode: BorderImage.Stretch
	    z:-1
	    source: "../img/r_20_shadow.png"
	 }


	Text {
            id: text1
	    y: 11
	    color: "#c4c0c0"
	    text: button_name
     anchors.right: parent.right
     anchors.rightMargin: 5
     anchors.left: parent.left
     anchors.leftMargin: 5
     anchors.bottom: parent.bottom
     anchors.bottomMargin: 10
     z: 2
	    wrapMode: Text.WordWrap
            smooth: true
	    font.pointSize: 15
            style: Text.Sunken
            styleColor: "#000000"
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
        }
        Item {
            id: picture
	    x: 0
	    y: 0
	    anchors.fill: parent
	    anchors.bottomMargin: 40
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0

            Rectangle {
                id: rectangle1
                radius: 20
		anchors.fill: parent
		anchors.bottomMargin: 0
                gradient: Gradient {
                    GradientStop {
                        position: 0
                        color: "#7c7c7c"
                    }

                    GradientStop {
                        position: 0.96
                        color: "#474747"
                    }
                }
                clip: true
                opacity: 1
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                anchors.topMargin: 10

                Image {
                    id: image1
		    x: 0
		    y: 0
		    anchors.rightMargin: 0
		    anchors.leftMargin: 0
		    anchors.topMargin: 0
		    anchors.bottomMargin: 0
                    scale: 1
                    z: 1
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
		    source: "../img/Coffee.png"
                }



            }
        }


    }
    MouseArea{
        id:button_mouse_area
        hoverEnabled: true
        anchors.fill: parent
        onEntered: {
            console.log('hover button')
            highlight.opacity = 0.3
        }
        onExited: {
             highlight.opacity = 0.0
        }
        onPressed: {
            pressed.opacity = 0.5
        }
        onReleased: {
            pressed.opacity = 0.0
        }
    }
    Rectangle {
        id: highlight
        color: "#e5f4fb"
        radius: 20
        opacity: 0
        anchors.fill: parent
        z: 1
    }
    Rectangle {
        id: pressed
        color: "#1f1f20"
        radius: 20
        opacity: 0
        anchors.fill: parent
        z: 1
    }
}

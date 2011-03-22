import QtQuick 1.0
Item {
    id: name
    property string product_name: ""
    width: 180
    height: 200

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

        Text {
            id: text1
            x: 36
            y: 43
            color: "#c4c0c0"
            text: "Kaffe Schwarz"
            wrapMode: Text.WordWrap
            smooth: true
            font.pointSize: 20
            style: Text.Sunken
            styleColor: "#000000"
            anchors.verticalCenterOffset: 60
            verticalAlignment: Text.AlignTop
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
        }
        Item {
            id: picture
            height: 130
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            Rectangle {
                id: rectangle1
                height: 120
                radius: 20
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
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: parent.top
                anchors.topMargin: 10

                Image {
                    id: image1
                    scale: 1
                    z: 1
                    smooth: true
                    fillMode: Image.PreserveAspectFit
                    anchors.fill: parent
                    source: "img/Coffee.png"
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

import QtQuick 1.0

Item {
    id: measure
    width: 400
    height: 80

    property int  value: 0
    property int  steps: 3
    property int  indicator_width: 2


    Text {
        id: text1
        y: 33
        text: "-"
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 50

        MouseArea {
            id: mouse_area2
            anchors.fill: parent
            onClicked: {
                if(value-1 >= 0)
                {
                    value--;
                    console.log("inkrement")
                    indicator_width = (rectangle2.width/100)+((rectangle2.width/steps)*value);
                }
            }
        }
    }

    Text {
        id: text2
        x: 361
        y: 33
        text: "+"
        anchors.rightMargin: (parent.width/100)*5
        font.bold: true
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 50

        MouseArea {
            id: mouse_area1
            anchors.fill: parent
            onClicked: {
                if(value+1 <= steps)
                {
                    value++;
                    console.log("inkrement")
                    indicator_width = (rectangle2.width/100)+((rectangle2.width/steps)*value);
                }
            }
        }
    }

    Rectangle {
        id: rectangle2
        clip: true

        height: (parent.height/100)*30
        color: "#dd672c"
        radius: 0
        anchors.leftMargin: 15
        anchors.rightMargin: 15
        anchors.left: text1.right
        anchors.right: text2.left
        border.color: "#d3d3d3"
        anchors.verticalCenter: parent.verticalCenter

        Rectangle {
            id: rectangle1

            width: indicator_width
            height: parent.height


            color: "#5a5a5a"
            anchors.verticalCenterOffset: 0
            anchors.left: parent.left
            anchors.leftMargin: 0

            border.color: "#e8e8e8"
            anchors.verticalCenter: parent.verticalCenter
        }
    }

}

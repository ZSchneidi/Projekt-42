import QtQuick 1.0

Item {
    id: main_view_layer
    anchors.fill: parent
    width:  800
    height: 600

    property int d_ADMIN_DELAY_TIME: 5000

    Rectangle {
        id: background
        anchors.fill: parent

        Button{
            anchors.centerIn: parent
            z:2
            product_name: "Kaffe Schwarz"
        }

        Rectangle {
            id: rectangle1
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#dddddd"
                }

                GradientStop {
                    position: 1
                    color: "#808284"
                }
            }
            anchors.fill: parent

            Item {
                id: admin_switch
                width: 50
                height: 50
                anchors.top: parent.top
                anchors.right: parent.right
                Rectangle {
                    color: "#a8b8c2"
                    opacity: 0.2
                    anchors.fill: parent
                }

                /*the timer is used to delay the appearance of the admin menu*/
                Timer {
                    id: admin_timer
                    interval: d_ADMIN_DELAY_TIME;
                    onTriggered: {
                        console.log('show admin panel');
                       // listViewBox.state = "shown"
                    }
                }
                MouseArea {
                    id: admin_mouse_area
                    opacity: 1
                    anchors.fill: parent
                    onPressed: {
                        console.log('admin pressed');
                        admin_timer.start()
                    }
                    onReleased: {
                        console.log('admin released');
                        admin_timer.stop()
                    }
                }
            }

        }
    }

}

import QtQuick 1.0


Item {

    property int d_ADMIN_DELAY_TIME: 200
    id: admin_switch
    width: 50

    anchors { right: parent.right; top: parent.top; bottom: parent.bottom }

    //Trigger to show the admin screen
    Rectangle {
		id: admin_trigger
		color: "#a8b8c2"
		opacity: 0.2
		height: 50
		width: 50
		anchors { right: parent.right; top: parent.top; }

		/*the timer is used to delay the appearance of the admin menu*/
		Timer {
			id: admin_timer
			interval: d_ADMIN_DELAY_TIME;
			onTriggered: {
				console.log('show admin panel');
				admin_screen.state = "shown_admin_screen"
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

    //Admin screen definition
    Rectangle{
		id: admin_screen
		anchors { right: parent.right; top: parent.top; bottom: parent.bottom}
		color: "#535353"
		MouseArea{
			anchors.fill: parent
			onClicked: {
				console.log('close admin')
				admin_screen.state = ""
			}
		}
		states: [
			State {
				name: "shown_admin_screen"
				PropertyChanges {
					target: admin_screen
					width: (admin_switch.parent.width/100)*40
				}
				PropertyChanges {
					target: admin_trigger
				}
			}
		]
		transitions: [

			Transition {
				from: ""
				to: "shown_admin_screen"
				reversible: true
				NumberAnimation { target: admin_screen; property: "width"; duration: 700; easing.type: "OutBack" }
			}
		]

    }



}

import Qt 4.7

Rectangle {
    id: rectangle2
    width: 640
    height: 480
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#cbced3"
        }

        GradientStop {
            position: 1
            color: "#3a3d3e"
        }
    }
    border.color: "#cacaca"

    Rectangle {
	//anchors.centerIn: parent
	id: rectangle1
        width: 281
        height: 102
	x: (parent.width/2)-(width/2)
	y: (parent.height/2)-(height/2)
        radius: 17
	gradient: Gradient {
	    GradientStop {
		position: 0
		color: "#bdbdbe"
	    }

	    GradientStop {
		position: 0.99
		color: "#525658"
	    }
	}
        transformOrigin: "Center"
        rotation: 3

        smooth: true
        opacity: 0.7
        border.width: 4
        border.color: "#64080f16"

        Text {
            id: text1
            x: 20
            y: 37
            width: 52
            height: 19
            text: "Welcome to Project-42"
            font.pointSize: 18
            anchors.leftMargin: 20
            anchors.topMargin: 37
            anchors.rightMargin: -79
            anchors.bottomMargin: -72
            anchors.fill: parent
        }

	MouseArea {
	    id: mouse_area1
	    anchors.fill: parent
	    hoverEnabled: true;
	    onEntered:{
		rectangle1.opacity = 0.7
		console.log('mouse entered')
	    }
	    onExited:{
		rectangle1.opacity = 1
		console.log('mouse leaved')
	    }
	    onClicked: viewportinterface.sendCoreAction(3)
	}
	states: State {
		     name: "center"; when: mouse_area1.pressed == true
		     PropertyChanges { target: rectangle1; x: 20; y: 150; rotation: -280; }
		 }

	transitions: Transition {
	    from: ""; to: "center"; reversible: true
	    ParallelAnimation {
		NumberAnimation { properties: "x,y,rotation"; duration: 1000; easing.type: Easing.InOutQuad }
		ColorAnimation { duration: 500 }
		}
	    }

    }

    Text {
	id:text2
        x: 483
        y: 316
        color: "#797a7c"
        text: "42"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 15
        opacity: 0.21
        styleColor: "#5e5757"
        smooth: true
        style: "Raised"
        font.family: "Cambria"
        font.strikeout: false
        font.underline: false
        font.italic: false
        font.bold: true
        font.pointSize: 99
	MouseArea {
	    id: mouse_area2
	    anchors.fill: parent
	    hoverEnabled: true;
	    onEntered:{
		text2.opacity = text2.opacity-0.1
		console.log('mouse entered')
		text3.opacity = 0.2
	    }
	    onExited:{
		text2.opacity = text2.opacity+0.1
		console.log('mouse leaved')
		text3.opacity = 0
	    }
	    onClicked: viewportinterface.sendCoreAction(0)
	}

    }
    Text {
	id: text3
	text: "Beenden"
	anchors.centerIn: text2
	opacity: 0
	font.pointSize: 20
    }

}
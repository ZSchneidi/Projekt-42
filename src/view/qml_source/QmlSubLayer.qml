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

    Loader{
	id: sale_loader
	anchors.fill: parent
	source: "pos_layout/PosScreen.qml"

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

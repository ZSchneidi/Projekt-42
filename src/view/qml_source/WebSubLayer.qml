import Qt 4.7
import QtQuick 1.0
import "WebUiLogic.js" as WebUiLogic
import "web_elements"


Item {
    id: web_ui_layer
    anchors.fill: parent

    Rectangle {
	anchors.fill: parent
	color: "#d7d7d7"
	z: -1
	Text {
	    id: main_test
	    anchors.centerIn: parent
	    text: "no ui objects initialized"
	}
    }

    Timer {
	id: screen_timer
	interval: 300;
	onTriggered: {
	    console.log('switch screen');
	    //WebUiLogic.showScreenByID('205594');
	}
    }
    MouseArea {
	id: sw_screen_mouse_area
	opacity: 1
	anchors.fill: parent
	onPressed: {
	    console.log('switch pressed');
	    screen_timer.start()
	}
	onReleased: {
	    console.log('switch released');
	    screen_timer.stop()
	}
    }

    Component.onCompleted:
	setUpUiElements();



    /*JAVASCRIPT DEFINITION*/

    function setUpUiElements()
	{
	initElements();
	WebUiLogic.showDefaultScreen();
	}

    function initElements ()
	{
	for (var i = 0;i < elementinterface.screen_count;i++)
	    {
	    WebUiLogic.createScreenObjects(elementinterface.getScreenObjectAt(i),i);
	    }
	for (var i = 0;i < elementinterface.buttonc_count;i++)
	    {
	    WebUiLogic.createButtoncObjects(elementinterface.getButtoncObjectAt(i),i);
	    }
	}

}









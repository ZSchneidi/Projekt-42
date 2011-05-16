import Qt 4.7
import QtQuick 1.0
import "../js_source/WebUiLogic.js" as WebUiLogic
import "web_elements"


Item {
    id: web_ui_layer
    anchors.fill: parent

    Rectangle {
		anchors.fill: parent
		color: "lightgray"
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
			WebUiLogic.showScreenByID('107535');
		}
    }

    MouseArea {
		id: sw_screen_mouse_area
		opacity: 1
		anchors.fill: parent
		onPressed: {
			console.log('switch pressed');
			screen_timer.start()
			getArr();
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
			WebUiLogic.createScreenObjects(elementinterface.getScreenObjectAt(i),i,web_ui_layer,elementinterface);
	    }
		for (var i = 0;i < elementinterface.buttonc_count;i++)
	    {
			WebUiLogic.createButtoncObjects(elementinterface.getButtoncObjectAt(i),i,web_ui_layer,elementinterface);
	    }
	    /* for each module create the eventHandling */
	    for (var i = 0; i < elementinterface.module_count; i++)
		{
			WebUiLogic.createEventhandling(elementinterface.getModuleAt(i),i);
		}
	}

	function getArr()
	{
		console.log(WebUiLogic.a_screen);
		console.log(web_ui_layer.children.length);
		for(var i = 0; i < web_ui_layer.children.length; i++ )
			{
			console.log(web_ui_layer.children[i]);
			if(web_ui_layer.children[i].objectType == "Screen")
				console.log(web_ui_layer.children[i].children[0].color);
			}
	}

}









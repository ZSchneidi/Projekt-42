import Qt 4.7
import QtQuick 1.0
import "../js_source/WebUiLogic.js" as WebUiLogic
import "web_elements"

/**
  * This complex componen is designed to visualize dynamically created objects.
  * These objects are created by the ConfigParser of the core application.
  * After initializing this Layer, a JavaScript funktion will be called to create all
  * necessary QML objects to represent the complete layout defined by an xml
  * based configuration.
  * In addition to that the modules also parsed from the xml config will define
  * the eventhandling. This will happen by passing qml layer events to the c++
  * layer and back.
  *
  */

Item {
    id: web_ui_layer
    anchors.fill: parent

    Rectangle {
		anchors.fill: parent
		color: "lightgray"
		Text {
			id: main_test
			anchors.centerIn: parent
			text: "no ui objects initialized"
		}
    }

	/*as soon as the Item is finished call ...*/
    Component.onCompleted:
		setUpUiElements();


    /*JAVASCRIPT DEFINITION*/

    function setUpUiElements()
	{
		initElements();
		WebUiLogic.showDefaultScreen();
		/*additional processes could be placed here*/
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
	}


	/**
	  * This function returns the array of screens stored in the
	  * WebUiLogic javascript environment which aren't accessable
	  * from other contexts.
	  */
	function getScreenArray()
	{
		return WebUiLogic.a_screen;
	}

}









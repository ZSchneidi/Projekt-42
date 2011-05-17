import QtQuick 1.0
import Event 0.1
import EventDefinition 0.1
import "../../js_source/generic_func.js" as Generic_func

/**
  *Representation of a ButtonC object.
  */
Item {
    id: buttonc
    z:10
    width: bgImage.width
    height: bgImage.height
    property string button_image_up: ""
    property string button_image_do: ""
    property string identifier: ""
    property string button_name: ""
    property bool default_screen: false
    property string visible_str: ""
    property string objectType: "ButtonC"

    Image {
		id: bgImage
		anchors.fill: parent
		source: button_image_up
		fillMode: Image.PreserveAspectFit
    }

    MouseArea{
		id: button_mouse_area
		anchors.fill: parent
		onPressed: {
			bgImage.source = button_image_do
			event.setEventType(EventDefinition.ButtonDown)
			viewportinterface.sendUiObjectEvent(event)

			//console.log(parent.parent.parent.getScreenArray());


		}
		onReleased: {
			bgImage.source = button_image_up
			event.setEventType(EventDefinition.ButtonUp)
			viewportinterface.sendUiObjectEvent(event)
		}
    }

	Event {
		id: event
		sourceID: identifier

	}

	Connections{
		target: viewportinterface
		onOutEventOnTarget: {

			Generic_func.performActions(event,buttonc,EventDefinition);

		}
	}

   function prepareObject()
	{
		if(visible_str == "N" || visible_str == "n")
			opacity = 0;
			//console.log(parent.parent.WebUiLogic.test());
	}

}

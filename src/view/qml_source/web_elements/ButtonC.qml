import QtQuick 1.0

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
			console.log("press button "+button_name);
		}
		onReleased: {
			bgImage.source = button_image_up
		}
    }

    function prepareObject()
	{
		if(visible_str == "N" || visible_str == "n")
			buttonc.opacity = 0;
	}
}

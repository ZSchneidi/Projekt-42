import Qt 4.7
import "pos_layout"

Item {
    id: main_view_layer
    anchors.fill: parent

    //onWidthChanged: console.log(parent.width);

	PosScreen{
		id: pos_screen
		anchors.fill: parent
	}

}


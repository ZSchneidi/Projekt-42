import QtQuick 1.0

Item {
    id: shadow
	anchors.fill: parent

	property alias shadow_image: shadow_img

	z: (parent.z -2)

	BorderImage {
			id:shadow_img
			anchors.fill: parent
			anchors { leftMargin: -10; topMargin: -10; rightMargin: -10; bottomMargin: -10 }
			border { left: 30; top: 30; right: 30; bottom: 30 }
			horizontalTileMode: BorderImage.Stretch
			verticalTileMode: BorderImage.Stretch
			z:-1
			source: "../img/r_20_shadow.png"
		}

}


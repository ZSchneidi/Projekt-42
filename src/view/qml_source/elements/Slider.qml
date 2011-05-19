import QtQuick 1.0

Item {
	id: slider; width: 300; height: 16

	// value is read/write.
	property real value: 50
	onValueChanged: updatePos();
	property real maximum: 1
	property real minimum: 1
	property int xMax: width - handle.width - 4
	onXMaxChanged: updatePos();
	onMinimumChanged: updatePos();

	function updatePos() {
		if (maximum > minimum) {
			var pos = 2 + (value - minimum) * slider.xMax / (maximum - minimum);
			pos = Math.min(pos, width - handle.width - 2);
			pos = Math.max(pos, 2);
			handle.x = pos;
		} else {
			handle.x = 2;
		}
	}

	Rectangle {
		anchors.fill: parent
		border.color: "white"; border.width: 0; radius: 8
		gradient: Gradient {
			GradientStop { position: 0.0; color: "#66343434" }
			GradientStop { position: 1.0; color: "#66000000" }
		}
	}

	Rectangle {
		id: handle; smooth: true
		y: 2; width: 30; height: slider.height-4; radius: 6
		gradient: Gradient {
			GradientStop {
				position: 0.00;
				color: "#d5d5d5";
			}
			GradientStop {
				position: 1.00;
				color: "#cfcccc";
			}
		}

	}
}

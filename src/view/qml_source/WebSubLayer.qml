import Qt 4.7

Rectangle {
    width: 640
    height: 480
    color: "#d7d7d7"

    Text {
	id: main_test
	anchors.centerIn: parent
	text: "This UI is generated from cfg files"
    }

    Text {
	id: machine_id

	text: elementinterface.screen_count
	onTextChanged: {
	    console.log();
	}
    }
    function foo ()
    {
	var i = 0;
	for (i;i <= 10;i++)
	{
	    console.log(i);
	}
    }

    Component.onCompleted: foo();
}





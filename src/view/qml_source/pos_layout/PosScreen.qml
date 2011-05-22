import QtQuick 1.0
import "../styles/StyleController.js" as Style

Item {
    width: 800
    height: 600

    property alias select_loader: selection_loader
    property alias bottom_info_loader: bottom_info_content
    property alias pos_menu_bar: pos_menu_bar

    property color title_text_color: Style.Text.title_text_color
    property int menu_width_percent: 0
    property int title_height_percent: 15
    property int bottom_info_height_percent: 0
    property int top_info_height_percent: 0
    property int system_title_size: 80
    property int system_time_size: 60
    property int system_date_size: 20
    property int datetime_width_percent: 30
    property int media_mode_interval: 23000
    property string title_font: "Impact"

    property string current_select_box: "HotSelectionBox.qml"
    property string initial_screen: "HotSelectionBox.qml"


    id: pos_screen
    /** Screen background declaration**/
    Rectangle {
		id:pos_screen_background
		gradient: Gradient {
			GradientStop {
				position: 0.00;
				color: Style.Color.pos_screen_background_top;
			}
			GradientStop {
				position: 0.48;
				color: Style.Color.pos_screen_background_mid;
			}
			GradientStop {
				position: 0.99;
				color: Style.Color.pos_screen_background_bottom;
			}
		}
		anchors.fill: parent
    }
    MouseArea{
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: (parent.height/100)*title_height_percent
        hoverEnabled: true
        onEntered: {
            switchToSaleMode();
        }
    }
    /** Screen title declaration **/
    Item {
		id: pos_screen_title
		anchors.top: parent.top
		anchors.right: parent.right
		anchors.left: parent.left
		height: (parent.height/100)*title_height_percent
		z: 2
        clip: true

		Rectangle{
			id: title_background
			anchors.fill: parent
			gradient: Gradient {
				GradientStop {
					position: 0.00;
					color: Style.Color.title_background_top;
				}
				GradientStop {
					position: 1.00;
					color: Style.Color.title_background_bottom;
				}
			}
			Image{
				id:schadow
				height: 10
				fillMode: Image.Stretch
				smooth: true
				opacity: 0.5
                source: "../img/schadow_15_bar.png"
				anchors.top: parent.bottom
				anchors.left: parent.left
				anchors.right: parent.right
			}
            Item {
                id: title
                anchors.left: parent.left
                anchors.right: date_time.left
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                Text {
                    id: pos_screen_title_text
                    anchors.fill: parent
                    color: title_text_color
                    text: viewportinterface.system_title
                    smooth: true
                    font.pixelSize: (pos_screen_title.height/100)*system_title_size
                    font.bold: true
                    style: Text.Raised
                    font.family: title_font
                }
            }


			Item {
				id: date_time
				anchors.top: parent.top
				anchors.bottom: parent.bottom
				anchors.right: parent.right
				width: (parent.width/100)*datetime_width_percent

				Text {
					id: pos_screen_clock
					color: title_text_color
					smooth: true
					anchors.horizontalCenter: parent.horizontalCenter
					anchors.bottomMargin: (parent.height/100)*30
					font.pixelSize: (parent.height/100)*system_time_size
					font.bold: true
					style: Text.Raised
					font.family: title_font
					Connections{
						target: viewportinterface
						onSystemTimeChanged: pos_screen_clock.text = new_time
					}
				}
				Text {
					id: pos_screen_day
					smooth: true
					font.italic: false
					anchors.horizontalCenter: parent.horizontalCenter
					anchors.bottomMargin: 10
					anchors.bottom: parent.bottom
					color: title_text_color
					font.pixelSize: (parent.height/100)*system_date_size
					style: Text.Raised
					font.family: title_font
					Connections{
						target: viewportinterface
						onSystemDateChanged: pos_screen_day.text = new_date
					}
				}
			}
		}
    }

    /** Screen menu declaration **/
    Item {
        id: pos_menu_bar_item
        anchors.top: pos_screen_title.bottom
        anchors.left: pos_screen.left
        anchors.bottom: pos_screen.bottom

        width: (parent.width/100)*menu_width_percent

        MenuBar{
            id:pos_menu_bar

        }
    }

    /** Screen selectbox declaration **/
    Item {
		id: pos_screen_select_box
        anchors.top: pos_screen_title.bottom
        anchors.left: pos_menu_bar_item.right
		anchors.bottom: pos_screen_bottom_info.top
		anchors.right: pos_screen.right
		Loader{
			id: selection_loader
			anchors.fill: parent
            source: initial_screen

			Component.onCompleted: {
				select_loader.item.state = "visible"
            }
		}

		/* JAVASCRIPT */

		function loadDetailScreen(source,product)
		{
			current_select_box = select_loader.source;
			select_loader.item.state = "invisible"
			select_loader.source = source;
			select_loader.item.state = "visible"
			if(select_loader.status == Loader.Ready)
			{
				select_loader.item.initProductData(product);
			}
		}

		function loadSelectionBox(source)
		{
			current_select_box = source;
            select_loader.source = source;
			if(select_loader.item !== null)
				select_loader.item.state = "invisible";
			if(bottom_info_loader.item !== null)
                bottom_info_loader.item.state = "invisible";
			if(select_loader.item !== null)
				select_loader.item.state = "visible";
		}

        function loadServScreen(product)
		{
            console.log(product.productCode);
            select_loader.source = "ServScreen.qml"
            select_loader.item.setProduct(product);
		}

        function returnToSelection()
        {
            selection_loader.source = current_select_box;
            select_loader.item.state = "visible";
            pos_menu_bar.state = "visible";

        }

    }

    /** Screen top info bar declaration **/
    Item {
		id: pos_screen_top_info
        anchors.left: pos_menu_bar_item.right
		anchors.right: pos_screen.right
		anchors.top: pos_screen_title.bottom
		height: (parent.height/100)*top_info_height_percent
		Rectangle{
			anchors.fill: parent
			color: Style.Color.pos_top_info_background
			opacity: 0.8
		}
    }

    /** Screen bottom info bar declaration **/
    Item {
		id: pos_screen_bottom_info
        anchors.left: pos_menu_bar_item.right
		anchors.right: pos_screen.right
        anchors.bottom: pos_screen.bottom
        clip:true
		height: (parent.height/100)*bottom_info_height_percent
		Rectangle{
			anchors.fill: parent
			color: Style.Color.pos_bottom_info_background;
		}
		Loader{
			id:bottom_info_content
			anchors.fill: parent
			source: ""
		}
    }

    function switchToMediaMode()
    {
        pos_menu_bar.state = "invisible";
        if(bottom_info_loader.item !== null)
            bottom_info_loader.item.state = "invisible";
        title_height_percent = 0;
        select_loader.source = "MediaScreen.qml";
    }
    function switchToSaleMode()
    {
        pos_menu_bar.state = "visible";
        pos_screen_select_box.loadSelectionBox(current_select_box);
        title_height_percent = 15;
    }


    Timer{
        id:media_mode_timer
        interval: media_mode_interval; running: false; repeat: false
        onTriggered: switchToMediaMode();
    }

    /*on completed building the pos_screen*/
    Component.onCompleted: {
        media_mode_timer.start();

    }

}

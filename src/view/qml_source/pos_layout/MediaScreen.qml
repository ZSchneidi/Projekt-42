import QtQuick 1.0
import "../styles/StyleController.js" as Style
import "../../js_source/GlobalVar.js" as GlobalVar
import Base 0.1


/***********************************************
File reference:
The example files shown in the mediascreen are downloaded from:

http://wallpaper-s.org/40__Organic_Coffee_Bean_Sack.htm
http://www.urbansouq.com/wp-content/uploads/2011/01/coffee1.jpg
http://de.flash-screen.com/free-wallpaper/uploads/200706/imgs/1182596504_1024x768_beautiful-coffee-set.jpg

************************************************/

/**
  * Reprsentation of a simple MediaScreen which can be used as a kind of
  * advertising area.
  */

Item {
    id: media_screen
    anchors.fill: parent
    property int current_index: 0
    property int switch_timeout: 5000
    Rectangle{
        id:background
        color: "#252525"
        anchors.fill: parent
        Image {
            id: media_view
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: ""
            sourceSize.width: media_screen.width
            sourceSize.height: media_screen.height
        }
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            parent.parent.parent.parent.switchToSaleMode();
        }
    }

    Component.onCompleted: {

        init_timer.start();
        console.log("show media "+Base.Init_Media);
        viewportinterface.sendMediaAction(Base.Init_Media);

    }

    Timer{
        id: switch_timer
        interval: switch_timeout; running: false; repeat: true
        onTriggered: getNextMedia();
    }
    Timer{
        id: init_timer
        interval: 500; running: false; repeat: true
        onTriggered: initMediaFiles();
    }

    function startMedia()
    {
        switch_timer.start();
        media_view.source = GlobalVar.media_files[current_index];
    }

    /*get the next media file*/
    function getNextMedia()
    {

        current_index++;
        if(current_index >= GlobalVar.media_files.length)
            current_index = 0;

        media_view.source = GlobalVar.media_files[current_index];

        switch_timer.start();
    }

    /*store url to media files in the js array*/
    function initMediaFiles()
    {
        GlobalVar.media_files[0] = "../img/media/example_1.jpg";
        GlobalVar.media_files[1] = "../img/media/example_2.jpg";
        GlobalVar.media_files[2] = "../img/media/example_3.jpg";
        startMedia()

    }
}

import QtQuick 1.0
import "elements"

/**
  * The MainViewLayer is the central qml file which dynamically loads the
  * necessary qml file depending on the InitMode
  */

Item {
    id: main_view_layer
    anchors.fill: parent

    Rectangle {
        id: background
        anchors.fill: parent

		/*The Loader is used to load the corresponding qml files depending on the InitMode*/
		Loader{
			id: sale_loader
			anchors.fill: parent
			source: viewportinterface.sublayer
		}

		Connections{
			target: viewportinterface
			onAboutDialogCalled: {
				help_dialog.system_revision = rev;
				help_dialog.system_name = name;
				help_dialog.system_author = auth;
				help_dialog.system_date = date;
				help_dialog.help_text = text;
				help_dialog.opacity = 1;
			}
			onHelpDialogCalled: {
				console.log(text);
			}
		}

		AboutDialog {
			id: help_dialog
			anchors.centerIn: parent
			opacity: 0
		}

		HelpDialog{

		}

		/*
		AdminPanel{
			id:admin_panal
			anchors.fill: parent
		}
		*/
    }
}


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
				about_dialog.system_revision = rev;
				about_dialog.system_name = name;
				about_dialog.system_author = auth;
				about_dialog.system_date = date;
				about_dialog.help_text = text;
				about_dialog.opacity = 1;
			}
			onHelpDialogCalled: {
				help_dialog.help_text = text;
				help_dialog.opacity = 1;
			}
		}

		AboutDialog {
			id: about_dialog
			anchors.centerIn: parent
			opacity: 0
		}

		HelpDialog{

			id: help_dialog
			anchors.centerIn: parent
			opacity: 0
		}

		/*
		AdminPanel{
			id:admin_panal
			anchors.fill: parent
		}
		*/
    }
}


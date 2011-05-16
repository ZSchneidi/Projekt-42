.pragma library
/**
  *This file provides all javascript logic necessary for the creation of the WebUI interface.
  */
Qt.include("GlobalVar.js")


/*
 * creates a screen object and store it in the a_screen array
 * these objects are created in the context of the web_ui_layer
 */
function createScreenObjects(obj,index,web_ui_layer,elementinterface)
    {
    var object;
    var component;
    component = Qt.createComponent("../qml_source/web_elements/Screen.qml");

    //if (component.status == Component.Ready)
		{
		object = component.createObject(web_ui_layer );
		}
    object.identifier = obj.id;
    if(obj.def == "Y" || obj.def == "y")
		{
		object.default_screen = true;
		}

    object.background_image = obj.bgimg;
    object.screen_name = obj.name;
    a_screen[index] = object;

    screens_ready = true;

    }

/*
 * creates all ButtonC object provided by the elementinterface
 * all ButtonC object will be stored in the a_buttonc array
 */
function createButtoncObjects(obj,index,web_ui_layer,elementinterface)
    {
    var object;
    var component;
    component = Qt.createComponent("../qml_source/web_elements/ButtonC.qml");
    //if (component.status == Component.Ready)
	object = component.createObject(getParentScreenByID(obj.iparent));
    object.identifier = obj.id;
    object.button_name = obj.name;
    var size = obj.getImageSize(obj.up_file);
    object.width = size.width;
    object.height = size.height;
    object.button_image_up = obj.up_file;
    object.button_image_do = obj.do_file;
    object.x = obj.x_pos;
    object.y = obj.y_pos;
    object.visible_str = obj.visible;
    object.prepareObject(web_ui_layer);
    a_buttonc[index] = object;

    }

function showDefaultScreen()
	{
    for(var i = 0; i < a_screen.length; i++)
	    {
		if(a_screen[i].default_screen == true)
			{
			a_screen[i].opacity = 1;
			}
	    }
	}

/*displays a screen by id*/
function showScreenByID(id)
    {
    for(var i = 0; i < a_screen.length; i++)
	{
	if(a_screen[i].identifier == id)
	    a_screen[i].showScreen();
	}
    }

/*returns the screen object by its id*/
function getParentScreenByID(id)
    {
    for(var i = 0; i < a_screen.length; i++)
	{
	if(a_screen[i].identifier == id)
	    return a_screen[i];
	}
    return false;
    }


function createEventhandling(obj,index)
	{
	//console.log(obj.mod_adr);
	}



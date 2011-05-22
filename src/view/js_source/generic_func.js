.pragma library
Qt.include("WebUiLogic.js")
Qt.include("GlobalVar.js")


/**
  * This controller function
  */
function performActions(event,object,EventDefinition)
	{
	object = Object(object);
	/*if the current object is the target*/
	if(event.targetID == object.identifier)
		{
		switch(event.eventType)
			{
			case EventDefinition.Hide:
				hide(object);
				break;
			case EventDefinition.Show:
				if(object.objectType == "Screen")
					{
					screenControl(object,event);
					}
				else
					show(object);
				break;
			default:
				break;
			}
		}
	}

//Action definition
function hide(object)
	{
	object.opacity = 0;
	}

function show(object)
	{
	object.opacity = 1;
	}

function showScreen(object)
	{
	object.opacity = 1;
	}

function hideScreen(object)
	{
	object.opacity = 0;
	}

/**
  * This function is called to control the visibility of the screens
  * according to the event passed to this function
  */
function screenControl(object,event)
	{
	/* this is an important step which is used to get the
	 * array of screens that is stored in the context of
	 * the WebSubLayer.
	 */
	var screen_arr = object.parent.getScreenArray();
	for(var i = 0; i < screen_arr.length; i++)
		{
		if(screen_arr[i].identifier == event.targetID)
			{
			showScreen(screen_arr[i]);
			}
		else
			{
			hideScreen(screen_arr[i]);
			}
		}
	}

/**
  * This function was designed to initialize qml Product objects with
  * the data of another product data.
  * This is just a temporary workaround, because there are some issues with
  * asigning product objects to qml Product objects.
  */
function initProductObject(product,object)
{
    object.productName = product.productName;
    object.productCode = product.productCode;
    object.productPrice = product.productPrice;
    object.productDesc = product.productDesc;
    object.productIngred = product.productIngred;
    object.productImage = product.productImage;
}









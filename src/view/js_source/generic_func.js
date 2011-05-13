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

		/*
		console.debug(event.eventTypeInt);
		console.log(object.identifier);
		console.log(event.targetID);
		*/
		switch(event.eventType)
			{
			case EventDefinition.Hide:
				hide(object);
				break;
			case EventDefinition.Show:
				if(object.objectType == "Screen")
					{
					showScreen(object);
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














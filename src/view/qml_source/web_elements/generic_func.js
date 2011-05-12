
/**
  * This controller function
  */
function performActions(event)
	{
	/*if the current object is the target*/
		if(event.targetID == identifier)
		{
		console.debug(event.eventTypeInt);
		console.log(identifier);
		console.log(event.targetID);
		switch(event.eventType)
			{
			case EventDefinition.Hide:
				hide();
				break;
			case EventDefinition.Show:
				if(objectType == "Screen")
					showScreen(event.targetID);
				else
					show();
				break;
			default:
				console.log("did nothing");
				break;
			}
		}
	}

//Action definition
function hide()
	{
	console.log("hide"+identifier);
	opacity = 0;

	}

function show()
	{
	console.log("show"+identifier);
	opacity = 1;
	}

function showScreen(target_screen)
	{
	console.log("show screen"+target_screen);
	console.log(a_screen);

	if( identifier == target_screen )
		opacity = 1;
	else
		opacity = 0;
	}















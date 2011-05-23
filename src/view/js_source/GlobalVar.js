.pragma library

var text_color = "#383737";

/*contains the screen objects which are provided by the elementinterface*/
var a_screen = new Array();
/*contains all ButtonC objects provided by the elementinterface*/
var a_buttonc = new Array();

var screens_ready = false;

/*used by the qml media screen*/
var media_files = new Array();
var media_index = 0;

/*price difinition*/
var milk_price = 0.20
var sugar_price = 0.10

var clicks = 0;

function isScreenReady()
{
}

function clicked()
	{
    clicks++;
	}

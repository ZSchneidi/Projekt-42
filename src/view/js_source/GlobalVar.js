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

var tes_arr = new Array("bla","wupp","foo","bar");

var clicks = 0;

function isScreenReady()
{
//console.log(screens_ready);
}

function clicked()
	{
	clicks++;
	//console.log(clicks+'clicks');

	//console.log('screen count '+a_screen.length);
	//console.log('button count '+a_buttonc.length);
	}

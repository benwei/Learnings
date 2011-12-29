
var load = require("./virtual_function.js")

if (typeof test === "undefined") {
	var test = {};
}

test.text = 'aa'

console.log(test);


var t1 = load.Test();
var t2 = load.Test();
t1.specificHandler = function () {
	console.log("t1:test 111");
		// a(); will error on firefox
		a =  function () {
		    console.log('a');
		}
		a();
	}
t1.a();
t2.a();

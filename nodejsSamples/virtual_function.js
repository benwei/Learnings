
// @file prototype.js
// Sample from Rayan_Dahl's presentation
// Add Ben's note
// code won't specificHandlerlock, it will show the "hello world" after 2 seconds. Then terminated.
//


function Test() {
     return { specificHandler:function() {
	     console.log("test.testspecificHandler");
	},
        a:function() {
		// 1 action
		this.specificHandler();
	        // 3 action
	} 
     };
}

var Test2 = {
	a:function(){
		     this.specificHandler();
	},
	specificHandler:function(){
		     console.log("test2.specificHandler");
	}
};

if (typeof exports === "undefined") {
	var exports = {};
}
exports.Test = Test;

function selftest() {
// virtual function
var t1 = Test();
var t2 = Test();
t1.specificHandler = function () {
	console.log("t1:test 111");
	}
t1.a();
t2.a();

// pattern singleton
var t1 = Test2;
var t2 = Test2;
t1.specificHandler = function () {
	console.log("t1test 222");
	}
t1.a();
t2.a()
}

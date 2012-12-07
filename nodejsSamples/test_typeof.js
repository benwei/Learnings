var util = require('util');

var h = {};
var a = [];
var b = 1;
var s = "";
var buf = new Buffer('');

function otypeof(obj) {
    var to = typeof(obj);
    if (to === 'object') {
        var pt = Object.prototype.toString.call(obj);
        console.log("pt ==> " + pt);
        if (pt == '[object Array]') {
            return "Array";
        } else if (pt == '[object Object]') {
            console.log("- " + util.inspect(obj));
        }
    } else if (to === 'function') {
        return to;
    }
    return to;
}

function cls () {
    this.__name__ = "class";
}

var c = new cls();

console.log("Hash : " + otypeof(h));
console.log("Str " + otypeof(s));
console.log("Array : " + otypeof(a));
console.log("Int : " + otypeof(b));
console.log("Buffer : " +  otypeof(buf));
console.log("Function : " +  otypeof(otypeof));
console.log("Class new: " +  otypeof(c));

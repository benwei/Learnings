var util = require('util');

var a = 10;
var g_map = {
   get: function () { return a; },
   value: a, /* equal to g_map.a = a */
   dump: function () {
	console.log("get() = " + this.get())
	console.log("value = " + this.value)
   }
}

g_map.dump();
a = 20;
console.log('changed a to ' + a);
g_map.dump();

var map_for_delete = { 'foo': 1, 'root': 2 };
console.log('origin map:' + util.inspect(map_for_delete));
delete map_for_delete['foo'];
console.log('delected foo from map:' + util.inspect(map_for_delete));

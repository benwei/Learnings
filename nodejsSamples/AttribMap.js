// @ AttribMap
// AttribMap class
AttribMap.prototype.constructor = AttribMap;

function AttribMap() {
	this.length = 0;
	this.info = [];
	this.keyinfo = [];
}

AttribMap.prototype.get = function(key) {
	if (this.info[key]) {
		return this.info[key].mvalue;
	} 
	return null;
}

AttribMap.prototype.set = function(key, val) {
	this.info[key] = { mvalue: val, mkey: key };
	this.keyinfo[this.length] = key;
	this.length++;
}

AttribMap.prototype.keyAtIndex = function(index) {
	return this.keyinfo[index];
}

AttribMap.prototype.count= function() {
	return this.length;
}

// main

var info = [];

info["a"] = {v: "a1" };
info["b"] = {v: "b2" };

console.log(info["a"]);
if (info["c"])
	console.log(info["c"]);

var amap = new AttribMap();
amap.set("x1", "1");
amap.set("x2", "2");

console.log("count=" + amap.count());

key = "x1";
console.log(key + ":" + amap.get(key));
key = "1";
console.log(key + ":" + amap.get(key));

for (var i = 0 ; i < amap.count(); i++) {
	var k = amap.keyAtIndex(i);
	console.log(k + ":" + amap.get(k));
} 


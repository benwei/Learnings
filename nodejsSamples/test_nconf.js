#!/usr/bin/env node

// install nconf
// npm install nconf

var nconf = require('nconf'),
    util = require('util'),
    fs = require('fs')

// try in memory key-value store by nconf

function kvstore(storename) {
	var env = storename;
	var store = nconf;
	//store.use('memory')
	var confname = __dirname + "/nconfig.json";
	store.file({file: confname});
	this.get = function (key) {
		return store.get(key);
	}

	this.set = function (key, value) {
		return store.set(key, value);
	}

	this.clear = function (key) {
		store.clear(key)
	}
	this.file = function (v) {
		store.file(v)
	}
	this.save = function () {
		store.save()
	}
	this.dump = function () {
		var d = fs.readFileSync(confname);
		console.log("dump: " + d);
	}
}


function main() {
	var sa = new kvstore('a')
	var sb = new kvstore('b')
	sa.set("a:a:c", 10);
	sa.set("a:b:c", 20);
	sa.set("a:c:c", 30);
	console.log("sa.get('a') = " + util.inspect(sa.get("a")));
	console.log("sb.get('a') = " + util.inspect(sb.get("a")));
	console.log("clear('a:c')");
	sa.clear("a:c");
	console.log("sa.get('a') = " + util.inspect(sa.get("a")));
	sa.save();
	sa.dump();
}

main()

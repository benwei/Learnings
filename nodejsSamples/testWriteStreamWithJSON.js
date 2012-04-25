#!/usr/bin/env node
var fs = require('fs');

strjson= '{"test1": "測試", "test2": "程式"}';

data = JSON.parse(strjson);
console.log("json string to map:", data);
sdata = JSON.stringify(data);
console.log("map to string", JSON.stringify(data));

function saveToJSONFile(filename, strdata) {
	var f = fs.createWriteStream(__dirname+ '/' + filename, {encoding: 'utf-8'});
	
	f.on('error', function (err) {
		console.log(err);
	})
	.on('close', function () {
		console.log('write data to ' + filename + ' successfully.');
	});
	
	f.write(strdata);
	f.end();
}

saveToJSONFile('test.json', sdata + '\n');



/*
* License: MIT
* (c) 2012 ben@staros.mobi 
*/

var fs = require('fs')

function BWFileParser(filename) {
	var self = this;
	var arr = new Array()
	var lineno = 0;

	this.padding = function (num, width) {
		var w = num.toString().length;
		r = ''
		var i = 0;
		for (; i < width - w; i++) {
			r += '0'
		}
		return r+num;
	}

	this.searchText = function (entries, ptn, found_cb) {
		var arrMatches;
		entries.forEach(function (buf, index) {
			arrMatches = buf.match(ptn) 
			if (arrMatches)
				found_cb(index, arrMatches)	
		});
	}

	this.toLines = function (data) {
		var s = data.toString('utf8')
		var buf = '';
		for (i = 0 ; i < s.length; i++) {
			if (s[i] == '\n') {
				arr[lineno] = buf
				buf = '';
				lineno++;
			} else {
				buf += s[i]	
			}
		}
	}

	this.parse = function (regexs, cb) {
		var data = fs.readFileSync(filename)
		self.toLines(data);
		regexs.forEach(function(regex) {
			var ptn = new RegExp(regex)
			self.searchText(arr, ptn, cb);
		});
	}
}

// samples
var ts = new BWFileParser('list.txt')
var ptns = [/^.*nconf.*$/, /^.*mime.*$/, /^.*trace.*$/];

ts.parse(ptns, function (lineno, found) {
	console.log("line[" + ts.padding(lineno,2) + "]: " + found)
});


// @file web-server2.js
// Sample from Rayan_Dahl's presentation

var http = require('http');

// fetch www.google.com every 2 seconds.
setInterval(function(req, res) {
	http.get({host: 'www.google.com'}, function(res) {
		console.log(res.headers);
		});
}, 2000);

// At the same time to serve client at 8000 port with hello world
var s = http.Server(function(req, res) { 
		res.writeHead(200, {'content-type:', 'text/plain'});
		setTimeout(function() {
		  res.end('hello world\n');
		}, 1000);
	});

s.listen(8000);


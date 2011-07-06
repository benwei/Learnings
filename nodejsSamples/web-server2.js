// @file web-server2.js
// Sample from Rayan_Dahl's presentation
// simplest http server, always replay "hello", then show "world" after 2 seconds

var http = require('http');

var s = http.createServer(function(req, res) {
     res.writeHead(200, {'content-type': 'text/plain'});
     res.write("hello\n");
     setTimeout(function() {
     res.end("world\n");}, 2000);
});

s.listen(8000);

/*
ben:~ boslab$ curl -i http://localhost:8000
HTTP/1.1 200 OK
content-type: text/plain
Connection: keep-alive
Transfer-Encoding: chunked

hello
==== 2 second later ===
world
*/


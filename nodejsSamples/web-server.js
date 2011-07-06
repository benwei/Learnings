// @file web-server.js
// Sample from Rayan_Dahl's presentation
// simplest http server, always replay hello world

var http = require('http');

var s = http.createServer(function(req, res) {
     res.writeHead(200, {'content-type': 'text/plain'});
     res.end("hello world\n");
});

s.listen(8000);

/**
ben:~ boslab$ curl http://localhost:8000
hello world
ben:~ boslab$ curl -i http://localhost:8000
HTTP/1.1 200 OK
content-type: text/plain
Connection: keep-alive
Transfer-Encoding: chunked

hello world
ben:~ boslab$
**/


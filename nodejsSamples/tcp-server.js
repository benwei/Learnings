// @file tcp-server.js
// simplest tcp server, first time show hello world, then always replay data from client
var net = require('net');

var server = net.createServer(function(socket) { 
	  socket.write("hello\n");
	  socket.write("world\n");
	  socket.on('data', function(data) {
		socket.write(data);
	});
   });

server.listen(8000);

/*
ben:~ boslab$ telnet localhost 8000
Trying ::1...
telnet: connect to address ::1: Connection refused
Trying fe80::1...
telnet: connect to address fe80::1: Connection refused
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
hello
world
data
data
test for reply
test for reply
Connection closed by foreign host.
*/

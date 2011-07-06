// @file chat-server.js
// Sample from Rayan_Dahl's presentation
// modified by ben
// simplest chat server 
var net = require('net');
var sockets = [];
var msgpool = [];
var server = net.createServer(function(socket) { 
	console.log('add socket:' + socket.fd);
	sockets.push(socket);
	msgpool.push('');

	// send the data to all socket connections
	socket.on('data', function(d) {
		var who = sockets.indexOf(socket);
		sockets[who].write(d);
		msgpool[who] += d;
		if (d == '\r\n' || d == '\n' || d == '\r') {
			if (msgpool[who].length > 0) {
				for (var i = 0; i < sockets.length; i++) {
					if (sockets[i] == socket) continue;
					sockets[i].write(who+" said: "+ msgpool[who] + '\n');
				}
				msgpool[who] = '';
			}
		} else {
			console.log('msgpool['+who+'] add: ' + d);
		}
	});

	// remove the disconnected socket, to avoid the excpetion
	socket.on('end', function() {
		var i = sockets.indexOf(socket);
		console.log('end socket:', sockets[i].fd);
		sockets.splice(i, 1);
		msgpool.splice(i, 1);
	});
   });

server.listen(8000);


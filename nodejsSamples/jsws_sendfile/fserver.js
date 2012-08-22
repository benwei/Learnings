
var WebSocketServer = require('ws').Server;
var http = require('http');
var express = require('express');
var app = express();
var util = require('util');

app.use(express.static(__dirname + '/public'));

var server_port = 8010;

var server = http.createServer(app);
server.listen(server_port);

var wss = new WebSocketServer({server: server});
//var wss = new WebSocketServer({port: server_port});
wss.on('connection', function(ws) {
    var filesize = 0;
    ws.on('message', function(message, flags) {
        if (flags.binary) {
            // console.log(util.inspect(flags));
            var msg = "server received " + flags.buffer.length + "bytes";
            filesize += flags.buffer.length;
            console.log(msg);
            ws.send(msg);
        } else {
            var obj = JSON.parse(message);
            if (obj.cmd == 'upload' && obj.state == 'done') {
                console.log('r: %s filesize: %d', obj.data, filesize);
                filesize = 0;
            } else {
                console.log('r: %s', message);
            }
            ws.send(message);
        }
    });
    ws.send('Hello, WS');
});

console.log("jschat server listen on " +  server_port + "...");

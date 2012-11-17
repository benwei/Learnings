var express = require('express'),
    http = require('http'),
    fs = require('fs'),
    WebSocketServer = require('ws').Server,
    util = require('util'),
    app = express();

var logger = {
    error: function (msg) {
               console.log("err:" + msg);
           },
    debug: function (msg) {
               console.log("debug:" + msg);
           }
}

var logFile = fs.createWriteStream('./test_ws_with_express.log', {flags: 'a'}); 

app.use(express.logger({stream: logFile}));

app.get('/', function(req, res){
    res.send('Hello World');
});

var port = 9999;
var server = http.createServer(app);
server.listen(port);

console.log('Express server started on port %s', port);

function verifyClient(info) {
    // console.log(info.req.connection.remoteAddress);
    return true;
}

// var wss = new WebSocketServer({server: server, verifyClient: verifyClient });
var wss = new WebSocketServer({server: server});

wss.on('error', function (err) {
    logger.error('wss error:' + err);
});

var that = {};
that.ws_id_num = 0;
that.clients = [];

wss.on('connection', function(ws) {
    that.ws_id_num++;
    var conn = {ws: ws, id: that.ws_id_num};
    that.clients.push(conn);
    logger.debug("ws client " + conn.id + " connected.");
    console.log("client ip: " + ws.upgradeReq.connection.remoteAddress + " port:" 
        + ws.upgradeReq.connection.remotePort);

    ws.on('message', function(message, flags) {
    });

    ws.on('close', function () {
        logger.debug("ws client " + conn.id + " disconnected.");
    });
});

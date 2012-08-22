// reference from https://github.com/einaros/ws
var WebSocket = require('ws'),
fs = require('fs');

if (process.argv.length <= 2) {
    console.log("syntax: <filename>");
    return ;
}

var ws = new WebSocket('ws://localhost:8010');

var filename = process.argv[2];

ws.on('open', function() {
    var msgobj = {cmd: 'file',
            state:'upload',
            data: 'file ' + filename + 'uploaded'}

    ws.send(JSON.stringify(msgobj));

    var data = fs.createReadStream(filename, {
        'flags': 'r',
        'encoding': 'binary',
        'mode': 0666,
        'bufferSize': 4 * 1024
    }).addListener( "data", function(chunk) {
        ws.send(chunk, {binary: true, mask: true});

    }).addListener( "close",function() {
        var msgobj = {cmd: 'file',
            state:'done',
            data: 'file ' + filename + 'uploaded'}
        ws.send(JSON.stringify(msgobj));
    });
});

ws.on('message', function(data, flags) {
    // flags.binary will be set if a binary data is received
    // flags.masked will be set if the data was masked
    console.log(data);
});


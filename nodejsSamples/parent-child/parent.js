// samples: http://nodejs.org/api/child_process.html
//
var cp = require('child_process');

var n = cp.fork(__dirname + '/sub.js');

n.on('message', function(m) {
    console.log('Parent-' + process.pid + ' got message:', m);
});

n.send({ hello: 'world from Parent-' + process.pid });

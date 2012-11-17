
var events = require('events')
, util = require('util');


function manager () {
   var _events;
}

manager.prototype = events.EventEmitter.prototype;

var earr = [];

[1, 2].forEach(function (v) {
    var m = new manager();

    m.on('test', function (data) {
        var n = v;
        console.log(n + ":" + data);
        console.log(n + ":" + util.inspect(m._events));
    });
    earr.push(m);
});

var t = earr[0];

t.on('test', function (data) {
    console.log('test2:' + data);
});

earr.forEach(function (m) {
m.emit('test', 'hello world!')
});


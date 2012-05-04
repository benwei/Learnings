var EventEmitter = require('events').EventEmitter,
    bomb = new EventEmitter();

console.log("bomb event binding");

var MAX_LISTENERS = 12;

// if you don't use setMaxListeners(), got the following warning while number of listeners is over 10.
// (node) warning: possible EventEmitter memory leak detected. 11 listeners added. Use emitter.setMaxListeners() to increase limit.
bomb.setMaxListeners(MAX_LISTENERS);

function indexBomb(bomb) {
	var bomb_event = bomb;
	return { spawn: function () {
			this.index++; 
			var index = this.index;
			var self = this;
			bomb_event.on('explode', function(msg) {
			    console.log('BOOM! (' + index + '/' + self.index + ') : ' +  msg);
			});
		},
		index: 0,
		explode: function () {
			console.log("bomb 'explode' event trigger "+ this.index + ' bombs');
			msg = 'exploded ' 
			bomb_event.emit('explode', msg);
		}
	}
}

var ib = new indexBomb(bomb)
for (var i = 0 ; i < MAX_LISTENERS ; i++) {
    ib.spawn();
}

ib.explode()

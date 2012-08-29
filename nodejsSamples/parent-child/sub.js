// samples: http://nodejs.org/api/child_process.html
// And then the child script, 'sub.js' might look like this:

process.on('message', function(m) {
    console.log('Child-' + process.pid + ' got message:', m);
});

process.send({ foo: 'bar' });

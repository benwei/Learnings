// samples from nodejs.org
//
var spawn = require('child_process').spawn,
grep  = spawn('grep', ['ssh']);

grep.on('exit', function (code, signal) {
    console.log('child [' + grep.pid + '] process terminated due to receipt of signal '+signal);
});

// send SIGHUP to process
grep.kill('SIGHUP');


// test this sample works well with windows cmd.exe
process.stdin.resume();
// but it doesn't work on cygwin tty due to error on setRawMode
// (the same testing result on node 0.6.8 and 0.6.15
require('tty').setRawMode(true);    

process.stdin.on('keypress', function (chunk, key) {
  process.stdout.write('Get Chunk: ' + chunk + '\n');
  if (key && key.ctrl && key.name == 'c') {
	console.log("\nquit");
	process.exit();
  }
});



var fs = require('fs');

var watcher = fs.watch('.', function (event, filename) {
	console.log(event + "+" + filename);
	if (filename == 'close') {
		watcher.close();
	}
})



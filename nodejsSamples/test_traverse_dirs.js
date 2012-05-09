var fs = require('fs');
var path = require('path');

function prefix_str(layer) {
	pstr = '';
	while (--layer >= 0) {
		pstr += '    ';
	}
	return pstr;
}

function listdirs(target_dir, layer) {
	if (typeof layer === 'undefined')
		layer = 0;

	fs.readdir(target_dir, function (err, files) {
		if (err) return ;
		console.log(prefix_str(layer) + "+-" + path.basename(target_dir));
		files.forEach(function (file, index, array) {
			fullpath = target_dir + '/' + file;
			var stat = fs.statSync(fullpath);
			if (stat.isDirectory()) {
				listdirs(fullpath, layer+1);
			} else {
				var sign = ' |-';
				if (index == array.length -1)
					sign = ' `-';
				console.log(prefix_str(layer) + sign + file + " (" + stat.size + ")");
			}
		});
	});
}

listdirs('.');

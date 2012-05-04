
var mime = require('mime');
function isImage(mimetype) {
	return mimetype.match(/image\/.*/);
}
function show_mime_type(filename) {
	var mimetype = mime.lookup(filename);
	console.log('mime-type:' + mimetype + ' -> ' + filename);
	if (isImage(mimetype)) {
		console.log('type is image');
	}
	console.log('extension-type:' + mime.extension(mimetype) + ' -> ' + filename);
}

process.argv.forEach(function (arg, index, array) {
	if (index > 1) {
	    show_mime_type(arg);
	}
});


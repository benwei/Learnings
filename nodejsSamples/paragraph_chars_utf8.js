//
//
var fs = require('fs')

function main() {
	
	if (process.argv.length < 3) {
		console.log("syntax: <filename>");
		return 1				
	}

	var filename = process.argv[2];
	var data = fs.readFileSync(process.argv[2], 'utf8');

	console.log(filename + ": total " + data.length + " characters, " +
	  Buffer.byteLength(data, 'utf8') + " bytes");
	var i = 0;
	for (i = 0; i < data.length; i++) {
		console.log(data[i]);
	}
}

main()

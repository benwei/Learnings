
var path = require('path');

var ret = path.relative(__dirname, '/');

console.log(ret);

ret = path.resolve('..', 'nodeSamples');

console.log(ret);


var mpath = path.join(__dirname, '../');
console.log(mpath);
ret = path.normalize(mpath+ '/..')
console.log(ret);
console.log('Current directory: ' + process.cwd());

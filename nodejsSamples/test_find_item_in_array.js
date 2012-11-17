var assert = require('assert');

var arr = ['cc', 'aa', 'bb'];

var i = arr.indexOf('aa')
console.log(i);
assert(i == 1, "element index should be 1");

var i = arr.indexOf('bb')
console.log(i);
assert(i == 2, "element index should be 2");

var i = arr.indexOf('dd')
console.log(i);
assert(i == -1, "element index should be -1 (not found)");

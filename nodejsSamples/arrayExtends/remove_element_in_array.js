
var obj_extend = require('./object_extend');

obj_extend.extendArray(Array);
var b = {b:2}
var arr = [ {a: 1} , b, {c:3} , {d:4}];

arr.remove(b);

arr.removeIndex(1);

console.log(arr);

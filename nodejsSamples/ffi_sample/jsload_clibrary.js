// please run command "npm install ffi" before run this sample
// sample from https://github.com/rbranson/node-ffi
var ffi = require('ffi');

var libm = ffi.Library('libm', {
  'ceil': [ 'double', [ 'double' ] ]
  });
  libm.ceil(1.5); // 2

  // You can also access just functions in the current process by passing a null
  var current = ffi.Library(null, {
    'atoi': [ 'int', [ 'string' ] ]
    });
  console.log(current.atoi('1234')); // 1234

// https://npmjs.org/package/errno-codes

var Error = require ("errno-codes");

console.log (Error.get (Error.ENOENT));

var errno = Error.getNextAvailableErrno ();
Error.create (errno, "TEST1", "test 1");
console.log (Error.get (Error.TEST1));
console.log (Error.get ("TEST1"));
console.log (Error.get (errno));


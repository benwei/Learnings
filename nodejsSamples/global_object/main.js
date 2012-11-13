
var ex1 =require('./ex1');
var ex2 =require('./ex2');
GLOBAL.a = 'test global a object'

console.log("dump global a: " + a);

var e1 = new ex1();
e1.show();

var e2 = new ex2();
e2.setMessage('apply a new global ex3 object');
e1.show();

// ex3 in GLOBAL, you don't need to specific the following line
// var e3 = GLOBAL.ex3;
var e3 = ex3;
console.log(e3.getName());
e3.setName('e3-1');
console.log(e3.getName());

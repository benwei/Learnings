var a = 10;
var b = 6;
var d = a/b;
var c = parseInt(d * 100) / 100;
console.log("(parseInt(" + a + " + " + b + ") * 100) / 100 = " + c); 
console.log("(Math.round(" + a + " + " + b + ") * 100) / 100 = " + Math.round(d * 100)/100); 
console.log("(" + a + " + " + b + ").toFixed(2) = " + d.toFixed(2)); 

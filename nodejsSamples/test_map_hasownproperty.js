
var map = { foo : 1 };

var array = [ 'foo' , 'x', 'y'];

array.forEach(function (obj){
	console.log(obj + ": " + map.hasOwnProperty(obj));
});

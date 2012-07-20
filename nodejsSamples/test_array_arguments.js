
function foo(a1, a2, a3) {
	var list = [a1, a2, a3];
	list.forEach(function (v, i) {
		console.log('arg' + i + ':' + v);
	});
}


function test() {
	var args = [4, 5, 6];
	foo.apply(this, args);
}

test();

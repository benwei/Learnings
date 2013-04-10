require('./lib/Method');

// reference the good parts : page 44
// Currying allows us to produce a new function by combining a function and an argument
Function.method('curry', function () {
    var slice = Array.prototype.slice;
    var args = slice.apply(arguments);
    var that = this;
    return function () {
        return that.apply(null, args.concat(slice.apply(arguments)));
    };
});

function Add (a, b)
{
    return a + b;
}

var add1 = Add.curry(1);
console.log(add1(6));    // 7

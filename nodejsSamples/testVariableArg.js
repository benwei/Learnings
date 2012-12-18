
// sample for selective args by key name
function testargs(a, b, args) {
    console.log('a=' + a)
    console.log('b=' + b)
    for (var k in args)
        console.log(k + '=' + args[k]);
}

testargs(1,2, {c:4, d:5, e:6});

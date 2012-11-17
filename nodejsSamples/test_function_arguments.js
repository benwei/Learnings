
function dumpcall(args) {
    var name = args.callee.name;
    var s = "call " + name +  '(';
    for(var k in args) {
        s += (k > 0 ? ',' : '') + args[k];
    }
    console.log(s+')');
}

function func(a, b, c) {
    dumpcall(arguments);
}

function func2(a, b, c, d) {
    dumpcall(arguments);
    var args = [];
    for(var k in arguments) {
        if (k >= func.length) 
            break;
        args.push(arguments[k]);
    };
    func.apply(this, args);
}


func2(4,5,6,7);


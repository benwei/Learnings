require('./lib/Method');

Number.method('add', function (b) {
    console.log(parseInt(this));
    return this + b;
});

String.method('atohex', function () {
    return parseInt(this);
});

function hexChar(v) {
    if (v < 10) {
        return v;
    }
    return (v - 10 + 30);
}

String.method('hex', function (){
    var s = '';
    for (var i = 0 ; i < this.length ; i++) {
        var v = this[i].charCodeAt(0);
        console.log("v: " + v);
        s+= v;
    }
    return s;
});

String.method('append', function (s) {
    return this + ' append ' + s;
});

console.log((3).add(5));
console.log("a".append('b'));
console.log("0xFE".atohex());
console.log("31A".hex());

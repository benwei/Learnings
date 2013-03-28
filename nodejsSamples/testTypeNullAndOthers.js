var BWUtil = require('./lib/BWUtil');

var undef;

function DummyClass() {
    this.name ="dummy class";
}

var cls = new DummyClass();

var tests = [
[],
null,
function () {},
{},
1,
undef,
"ss",
1.1,
true,
cls
];

tests.forEach(function (a) {
var t = BWUtil.type(a);
if (t === 'object') {
console.log(BWUtil.objectType(a));
} else
console.log(t);
});


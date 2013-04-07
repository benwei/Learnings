require('./lib/Method');

function SOTestCase(name) {
    this.name = name;
    this.data = "SOTestCase";
}

SOTestCase.method('dumpBytes', function(){
    console.log("------<<" + this.name + ">>------");
    var bytes = this.data.toBytes();
    bytes.forEach(function (v, i) {
        console.log("d["+ i + "]=" + v);
    });
});


var MyTestCase = function (name, data) {
    this.name = name;
    this.data = data;
}.inherits(SOTestCase);

var myTest = new MyTestCase("test1", "\n\011hello");
myTest.dumpBytes();

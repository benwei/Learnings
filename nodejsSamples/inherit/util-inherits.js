var util = require('util');
// util.inherits
// reference http://nodejs.org/docs/latest/api/util.html#util_util_inherits_constructor_superconstructor

function BaseClass(name) {
    self = this;
    self.basename = name || "BaseClass"
    self.showClassName = function () {
        console.log("class name is " + self.basename);
    }

    self.power = function (v) {
        return v * v;
    }
}

function TestClass() {
    BaseClass.call(this, "TestClass");
    self.calc = function (v) {
        console.log("TestClass: showClassName: " + self.power(v));
    }
}

util.inherits(TestClass, BaseClass);

var testcls = new TestClass();

var ret = (testcls instanceof BaseClass); // true
console.log("testcls instanceof BaseClass is " + ret);
var ret = (TestClass.super_ === BaseClass); // true
console.log("TestClass.super_ === BaseClass is " + ret); 

testcls.showClassName();
testcls.calc(10);

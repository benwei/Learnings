
function Parent(key, value) {
    this.key = key;
    this.value = value;
    this.init = function () {
	this.name = 'parent';
    }
    this.getKey = function () {
	return this.key;
    }
    this.getValue= function () {
	return this.value;
    }
}

function ClassA(defvalue) {
    this.getName = function () { return this.name };
    this.init = function () {
	this.name = this.key + '_' + this.value;
    }
}

ClassA.prototype = new Parent('class', 'a');
var a = new ClassA();
a.init();

console.log(a.getName());
console.log(a.getKey());
console.log(a.getValue());


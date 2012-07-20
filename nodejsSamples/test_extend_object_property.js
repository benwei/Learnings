

function ClassA ()
{
	var self = this;

	this.defname = function () {
		return 'this is a class';
	}

	this.show = function () {
		console.log('ClassA:' + self.defname());
	}
	this.dump = function () {
		console.log("this is a property for testing clone");
	}
}

function ClassB ()
{
	this.defname = function () {
		return 'this is b class';
	}

	this.show = function() {
		console.log('ClassB');
	}
}

function propertyClone(src, dst, propertyName)
{
var dn = Object.getOwnPropertyDescriptor(src, propertyName);
Object.defineProperty(dst, propertyName, dn);
}

var a = new ClassA();
var b = new ClassB();

a.show()
b.show()
propertyClone(a, b, 'show')

console.log("after clone property to overwrite origin 'show'");
b.show()
propertyClone(a, b, 'dump')
console.log("after clone property to create 'dump'");

b.dump()

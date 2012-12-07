// http://stackoverflow.com/questions/1919295/can-i-set-the-type-of-a-javascript-object
// helper function
var createObject = function (o) {
    function F() {}
    F.prototype = o;
    return new F();
};

function Bicycle(tires) {
    var that = createObject(Bicycle.prototype); // inherit from Bicycle.prototype
    that.tires = tires;                         // in this case an empty object
    that.toString = function () {
        return 'Bicycle with ' + that.tires + ' tires.';
    };

    return that;
}
var bicycle1 = Bicycle(2);
console.log("bicycle1 instanceof Bicycle is " + 
        (bicycle1 instanceof Bicycle)); // true

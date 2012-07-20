
// http://stackoverflow.com/questions/1584370/how-to-merge-two-arrays-in-javascript
var a=new Array('n','b','c','d');
var b=new Array('m','d','z','x');
var c=new Array('a','x','y','z');
var d=a.concat(b,c);

console.log('== using built-in concat ==');
console.log(d);

// remove duplicate key
Array.prototype.unique = function() {
    // return a new array from this
    var r = this.concat();
    for(var i=0; i<r.length; ++i) {
        for(var j=i+1; j<r.length; ++j) {
            if(r[i] === r[j])
                // remove one item in index j
                r.splice(j, 1);
        }
    }

    return r;
};

console.log("== using prototype unique ==");
console.log(d.unique());

// http://documentcloud.github.com/underscore/#union
try {
    var _ = require('underscore');
    var r = _.union(a, b, c);
    console.log("== using underscore ==");
    console.log(r);
} catch(e) {
    console.log("Reminder: npm install underscore");
}

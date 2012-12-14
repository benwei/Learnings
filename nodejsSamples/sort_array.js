// reference http://stackoverflow.com/questions/979256/how-to-sort-an-array-of-javascript-objects
var util = require('util');

var sortByHashKey = function(field, reverse, primer){
   var key = function (x) {return primer ? primer(x[field]) : x[field]};
   return function (a,b) {
          var A = key(a), B = key(b);
          return (((A < B) ? -1 :
                                 (A > B) ? +1 : 0)) * [-1,1][+!!reverse];                  
      }
}

function sortByArray(reverse) {
   return function (A,B) {
          return (((A < B) ? -1 : (A > B) ? +1 : 0)) * [-1,1][+!!reverse];                  
   }
}

function newKeyItem(pkey, index) {
    return {
        key: pkey,
        index: index
    };
}

var t = [ 'cc', 'dd', 'aa', 'mm' ];
var objs = [];

t.forEach(function (v, i) {
    objs.push(newKeyItem(v, i));
});

console.log("array origin:" + t);
t.sort(sortByArray(true));
console.log("sorted:" + t);

console.log("array origin:" + util.inspect(objs));
objs.sort(sortByHashKey('key', false));
console.log("sorted:" + util.inspect(objs));


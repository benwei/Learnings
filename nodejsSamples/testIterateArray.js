
var dump = function (i, v)  {
    console.log(i + "->" + JSON.stringify(v));
}

console.log("iterate method 1");
var arr = [ {a:1}, {b:2}, {c:3} ];
for (var i in arr) {
    dump(i, arr[i]);
}

console.log("iterate method 2");
arr.forEach(function (v, i){
    dump(i, v);
});

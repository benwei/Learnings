var assert = require('assert'),
SpentTime = require('./lib/SpentTime');


var loop = 100000;

function quotIt(item) { 
    return "'" + item + "'";
}

function idListByKey(items, key) {
    if (items === undefined || items.length == 0)
        return "";

    var idList = quotIt(items[0][key]);
    for (var i = 1; i < items.length; i++) {
        idList +=  ",'" + (items[i][key] + "'");
    }
    return idList;
}

function idListByKey2(items, key) {
    if (items === undefined || items.length == 0)
        return "";

    var arr = [];
    for (var i = 0; i < items.length; i++) {
        arr.push("'" + items[i][key] + "'");
    }

    return arr.join(",");
}

var testerIDArray = [];
for (var i = 100 ; i < 199 ; i++) {
    testerIDArray.push({id: "abcd-efgh-ijkl-m" + i});
}

function test1() {
    for (var i = 0 ; i < loop; i++) {
        idListByKey(testerIDArray, 'id');
    }
}
function test2() {
    for (var i = 0 ; i < loop; i++) {
        idListByKey2(testerIDArray, 'id');
    }
}

function showSpentTime(n, t) {
    console.log("case " + n +  " in " + t + 'ms');
}

var m = idListByKey(testerIDArray, 'id')
var m2 = idListByKey2(testerIDArray, 'id')
assert((m == m2), "failure");

var st = new SpentTime();
test1();
showSpentTime(1, st.diff());

var st2 = new SpentTime();
test2();
showSpentTime(2, st2.diff());


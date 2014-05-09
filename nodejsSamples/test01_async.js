#!node
// setup first
//  npm install async
var async = require('async');

var mycallstack = [];
var verbose = 0

function dlog(func_name, msg)
{
    if (verbose)
        console.log("function " + func_name + " was called ");
    mycallstack.push(func_name + "()");
}

function dumpstack(callstack)
{
    for (var i = 0; i < mycallstack.length; ++i) {
        console.log(mycallstack[i]);
    }
}

var a = function (callback)
{
    setTimeout(function(){
        dlog("a");
        callback(null, 1);
    }, 50);
}

var b = function (callback)
{
    setTimeout(function(){
        dlog("b");
        callback(null, 2);
    }, 100);
}

var c = function (callback)
{
    setTimeout(function(){
        dlog("c");
        callback(null, 3,3);
    }, 25);
}

function emptyArray (array) 
{
    while (array.length > 0)
        array.pop();
}

function test_series () {
    console.log("async.series(a, b, c)");
    emptyArray(mycallstack);
    async.series([a, b, c], function(err, results){
        dumpstack(mycallstack);
        console.log(results);
    });
}

console.log("async.parallel(a, b, c)");
async.parallel([a, b, c], function(err, results) {
    dumpstack(mycallstack);
    console.log(results);
    setTimeout(function (){
        test_series(); }, 200);
});


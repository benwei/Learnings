#!/usr/bin/env node
var array = ['1', '3', '5']
var a = JSON.stringify(array) + '.join(\', \') => '+ array.join(', ');
console.log(a);

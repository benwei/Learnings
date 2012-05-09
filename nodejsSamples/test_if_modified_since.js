
var sdt = new Date('Mon Apr 30 2012 12:10:10 GMT+0800 (CST)')
var ddt = new Date('Mon, 30 Apr 2012 04:10:10 GMT')

console.log('sdate: ' + sdt);
console.log('ddate: ' + ddt);
var s = sdt.getTime();
var d = ddt.getTime();
console.log('compare_s_and_d(' + s + ',' + d + ')=' + (d==s));

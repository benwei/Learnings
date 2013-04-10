var DateDiffer = require('./lib/DateDiffer');

var dd1 = new DateDiffer();

for (var i = 0; i < 10; i++) {
    dd1.reset()
    var counter = 10000000;
    var a=0;
    while (counter-- > 0) {
        a++;
    }

    console.log(dd1.difference() + " ms");
}

var startDate = new Date('Thu Mar 20 2013 17:20:09 GMT+0800 (CST)');
var dd2 = new DateDiffer(startDate);
var days = dd2.differenceInDays();
console.log(days + " day(s)");


var d = new Date();

var timestamp = "" + d.getTime();
console.log("timestamp: " + timestamp);

var secondsInHour = 3600 * 1000;
var secondsInDay = 86400 * 1000;
var hours = (timestamp / secondsInHour)

var days = (timestamp / secondsInDay)

    var timestampHour = hours.toFixed(0) * secondsInHour;
    var timestampDay = days.toFixed(0) * secondsInDay;
    var mHour = new Date(timestampHour);
    var mDay = new Date(timestampDay);

    console.log(d);
    console.log(mHour);
    console.log(mDay);


    // compare string
    function DateTest(str) {
        var self = this;
        self.str = str;
        var d = new Date(str);
        this.show = function () {
            console.log("-->" + d);
        }

    }

var a = new DateTest("2012-11-05T16:00:00Z");
var b = new DateTest("2012-11-06T11:00:00Z");
var c = new DateTest("2012-11-06T16:00:00Z");

[a, b, c].forEach(function (value, index) {
    value.show();
});

function DateRangeTest(left, right) {
    var that = {};

    that.showExpr = function(l, c, r) {
        console.log(l + " <= " + c + " < " + r);
    }

    that.showExprNot = function(l, c, r) {
        console.log(not + "  " + l + " <= " + c + " < " + r);
    }

    that.strInRange = function (src) {
        if (left <= src && str < str ) {
            that.showExpr(left, src, right);
            return true;
        }
        that.showExprNot(left, src, right);
        return false;
    }

    that.inRange = function (src) {
        if (left.str <= src.str && src.str < right.str ) {
            that.showExpr(left.str, src.str, right.str);
            return true;
        }
        that.showExprNot(left.str, src.str, right.str);
        return false;
    }
    return that;
}

var drt = DateRangeTest(a, c);
var r = drt.inRange(b);
if (r) {
    console.log("passed");
} else {
    console.log("failed");
}



// reference: https://github.com/csnover/js-iso8601/blob/master/iso8601.js


function timeFromISO8601TZ(dateString)
{
    var numericKeys = [ 1, 4, 5, 6, 7, 10, 11 ];
    // ES5 §15.9.4.2 states that the string should attempt to be parsed as a
    // Date Time String Format string before falling back to any
    // implementation-specific date parsing, so that’s what we do, even if
    // native implementations could be faster
    //            1 YYYY                2 MM       3 DD           4 HH    5 mm       6 ss        7 msec        8 Z 9 ±    10 tzHH    11 tzmm
    if ((struct = /^(\d{4}|[+\-]\d{6})(?:-(\d{2})(?:-(\d{2}))?)?(?:T(\d{2}):(\d{2})(?::(\d{2})(?:\.(\d{3}))?)?(?:(Z)|([+\-])(\d{2})(?::(\d{2}))?)?)?$/.exec(dateString))) {
        // avoid NaN timestamps caused by “undefined” values being passed to Date.UTC
        for (var i = 0, k; (k = numericKeys[i]); ++i) {
            struct[k] = +struct[k] || 0;
        }

        // allow undefined days and months
        struct[2] = (+struct[2] || 1) - 1;
        struct[3] = +struct[3] || 1;

        if (struct[8] !== 'Z' && struct[9] !== undefined) {
            minutesOffset = struct[10] * 60 + struct[11];

            if (struct[9] === '+') {
                minutesOffset = 0 - minutesOffset;
            }
        }

        timestamp = Date.UTC(struct[1], struct[2], struct[3], struct[4], struct[5] + minutesOffset, struct[6], struct[7]);
//        timestamp = Date.UTC(struct[1], struct[2], struct[3], struct[4], struct[5] + minutesOffset) ; // , struct[6], struct[7]);
        return timestamp;
    }
}


/* use a function for the exact format desired... */

function pad(n){return n<10 ? '0'+n : n}

function toISODateString(d){
    return d.getUTCFullYear()+'-'
    + pad(d.getUTCMonth()+1)+'-'
    + pad(d.getUTCDate())+'T'
    + pad(d.getUTCHours())+':'
    + pad(d.getUTCMinutes())+':'
    + pad(d.getUTCSeconds())+'Z'
}

function toLocal8601DateString(d) {
    var datestr = d.getFullYear()+'-'
    + pad(d.getMonth()+1)+'-'
    + pad(d.getDate())+'T'
    + pad(d.getHours())+':'
    + pad(d.getMinutes())+':'
    + pad(d.getSeconds());

    var tz = d.getTimezoneOffset();
    if (tz < 0) {
        tz = (-tz);
        datestr += '+';
    } else {
        datestr += '-';
    }
    datestr += pad(tz/60) + ":" + pad(tz%60);
    return datestr;
}

function main () {
    var d = new Date();
    console.log(toISODateString(d)); // prints something like 2009-09-28T19:03:12Z

    var src = "2012-09-06T15:31:00+08:00";
    var t = timeFromISO8601TZ(src);
    console.log(t);
    var m = new Date(t);
    utcstring = toISODateString(m);

    console.log("convert " + src + " to " + utcstring);

    if (utcstring != "2012-09-06T07:31:00Z" ) {
        console.log("incorrect tranlate from 8601+tz to UTC-8601");
    }

    datestring = toLocal8601DateString(m);
    console.log(datestring);
}

main()

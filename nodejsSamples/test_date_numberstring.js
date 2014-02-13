
// the get the local date time
var getDateNumberString = function (t) {
    return padStr(t.getFullYear()) +
           padStr(1 + t.getMonth()) +
           padStr(t.getDate()) +
           padStr(t.getHours()) +
           padStr(t.getMinutes()) +
           padStr(t.getSeconds());
}

function getUTCDateNumberString(d){
    return d.getUTCFullYear() +
        padStr(d.getUTCMonth()+1) +
        padStr(d.getUTCDate()) +
        padStr(d.getUTCHours()) +
        padStr(d.getUTCMinutes()) +
        padStr(d.getUTCSeconds());
}

function padStr(i) {
    return (i < 10) ? "0" + i : "" + i;
}

var getNowDateNumberString = function ()
{
    return getDateNumberString(new Date());
}

var getNowUTCDateNumberString = function ()
{
    return getUTCDateNumberString(new Date());
}


console.log("UTC: " + getNowUTCDateNumberString());
console.log("NOW: " + getNowDateNumberString());

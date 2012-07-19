

var a = [0, 1, 2, 3, 4]
function toSubArray (arr, start, end) {
    var r = [];
    for (var i = 0,l=arr.length; i < l; i++) {
        if (i >= start && i <= end) {
            r.push(arr[i]);
        }
    }
    return r;
}

var b = toSubArray(a, 1, a.length-2);

console.log(b);


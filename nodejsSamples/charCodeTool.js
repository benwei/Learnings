var fs = require('fs');


var toHexString = function (data) {
    var output = [];
    var hexStr = '0x';
    for(var i = 0; i < data.length ; i++) {
        var h = data.charCodeAt(i).toString(16);
        output.push(h);
        hexStr += h;
    } 

    console.log(output);
    console.log(hexStr);
}

var toCharCode = function (data) {
    console.log(String.fromCharCode(parseInt(data)));
}

var codeWithin = function (code, low, high)
{
    return (low >= code && code <= high);
}

var visibleCode = function (code) {
    return codeWithin(code,48,90)
     || codeWithin(code,106,111);
}

var listCharCode = function (data) {
    var str = '  ';
    for (i = 0; i < 128; i++) {
        if ((i & 0x7) == 0) {
            console.log("0x" + i.toString(16) + " " + str);
            str='';
        } 
        if (visibleCode(i)) {
            str += " " + String.fromCharCode(i);
        } else {
            str += " ?";
        }
    }
}

var esacpeCode = function (data) {
    var filename = data;
    var content = fs.readFileSync(__dirname + "/" + filename);
    var output = '';

    for (var i = 1; i < content.length; i++) {
        try {
        var c = content[i]; 
        } catch (e) {
            console.log("error at " + i);
            break;
        }
        if (c > 127) {
            output += "\\x" + c.toString(16);
        } else {
            output += String.fromCharCode(content[i]);
        }
    }

    console.log(output);
}

var syntax = function () {
    console.log('syntax: <option> <string>');
    console.log('option: hex | code | list | esc');
    console.log('esc <file> -- escape char > 127');
}


// main

var func = {
    'c': toCharCode,
    'code': toCharCode,
    'h': toHexString,
    'hex': toHexString,
    'l': listCharCode,
    'list': listCharCode,
    'e': esacpeCode,
    'esc': esacpeCode,
}


if (process.argv.length < 3) {
    return 1;
}

var opt = process.argv[2];
var data = process.argv[3];

var f = func[opt];
if (f) {
    r = f(data);
}

process.exit(r);

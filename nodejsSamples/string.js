
var path = "http://test.com/"

console.log("replace protocol =", path.replace(/^http/, "https"));
console.log("unescape(" + path + ")=" + escape(path));
http_sign = "://"
// indexOf not match return -1
console.log("indexof("+ http_sign +")=" + path.indexOf(http_sign));
escaped_str="%30%31%32";
console.log("unescape(" + escaped_str + ")=" + unescape(escaped_str));

var ints = new Array("1da", "a5b", "abc");

for (var s in ints ) {
	console.log("parseInt("+ ints[s] +")=" + parseInt(ints[s]));
}

ints[ints.length] = "test";
console.log("ints.append(test)=" + ints.length);

case_test_str="aBcD";
console.log("toLowerCase("+case_test_str+")", case_test_str.toLowerCase());
console.log("toUpperCase("+case_test_str+")", case_test_str.toUpperCase());

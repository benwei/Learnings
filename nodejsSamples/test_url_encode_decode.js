var assert = require('assert');

var encoded_session_token = "FXoA4LJ6jqNak4ix2Vkw9bbO.oGMRMACn5CFpnf%2Bx8DlO1HAfZI6HsJBao6ww5jLNO4Y"
var session_token = "FXoA4LJ6jqNak4ix2Vkw9bbO.oGMRMACn5CFpnf+x8DlO1HAfZI6HsJBao6ww5jLNO4Y"

// encodeURIComponent
var ret = decodeURIComponent(encoded_session_token)
if (ret == session_token) {
    console.log("urldecode value ok")
}
assert(ret == session_token, "decoded data should be the same")

var ret2 = encodeURIComponent(session_token);
if (ret2 == encoded_session_token) {
    console.log("urlencode value ok")
}

assert(ret2 == encoded_session_token, "encoded data should be the same")



var buf = new Buffer(4);
buf.writeUInt8(0x0, 0);
buf.writeUInt8(0x0, 1);
buf.writeUInt8(0x2, 2);
buf.writeUInt8(0x0, 3);

console.log(buf);
console.log(buf.readUInt32BE(0));
console.log(buf.readUInt32LE(0));

var ntohl = function(buf, i) {
    return ((0xff & buf[i]) << 24) |
           ((0xff & buf[i + 1]) << 16) |
           ((0xff & buf[i + 2]) << 8) |
           ((0xff & buf[i + 3]));
};
var n = ntohl(buf, 0);
console.log("ntohl ==>" + n);

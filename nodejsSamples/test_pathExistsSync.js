require('should')
var path = require('path')

var fn = __dirname + "/log/wf00_all.log";
var ret = path.existsSync(fn);
ret.should.equal(true);

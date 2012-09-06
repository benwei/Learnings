define([], function(require) {
    var util = require('util');
    var info = {
        a: 1,
        b: {c : 2}
    }
    return "sub module loaded info:" + util.inspect(info);
});

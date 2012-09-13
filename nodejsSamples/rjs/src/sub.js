define(function(require) {
    var info = {
        a: 1,
        b: {c : 2}
    }
    return "sub module loaded info:" + JSON.stringify(info);
});

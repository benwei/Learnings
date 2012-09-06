var requirejs = require('requirejs');

requirejs.config({
nodeRequire: require
});

requirejs(['entry'],
function(entry) {
        entry.run();
});

var requirejs = require('requirejs');

requirejs.config({
nodeRequire: require
});

requirejs(['sample'],
function(sample) {
        sample.test();
});

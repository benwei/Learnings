define(['strangers'], function(strangers) {

return {
    test: function() {
        var leading = 'Hello';
        var sentence = 'my first sample for google closure compiler';
        console.log(leading + ', ' + sentence + '.');

        strangers.hi(leading);
    }
}

});


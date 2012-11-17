// for requirejs load
define(["sub"], function( sub ){
    return {
        exec: function () {
            console.log("exec sub return message: " + sub);
        }
    }
});

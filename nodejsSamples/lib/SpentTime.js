// from https://gist.github.com/4232236
function SpentTime () {                                                                                                                                              
    this.reset = function () {
        start = new Date(); 
    }
    this.diff = function () {
        var now = new Date();
        return (now.getTime() - start.getTime()) 
    }
    var start = new Date();
}

module.exports = SpentTime;

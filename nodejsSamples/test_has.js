
function Tool(func) {
    var self = this;
    self.has = function (func) {
        if (typeof func === 'function') {
            return true;
        }
        return false;
    }
}

var tool = new Tool();

function Calculater () {
    var self = this;
    self.sum = function (a, b) {
        return a+b;
    };
}

var calc = new Calculater();

if (tool.has(calc.sum)) {
    console.log(calc.sum(2,3));
}

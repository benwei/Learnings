
module.exports = function () {
    this.setMessage = function(a)
    {
        GLOBAL['a'] = a;
    }

    function ex3 (name) {
        var self = this;
        self.name = name;
        self.setName = function(n) {
            self.name = n;
        }
        self.getName = function() {
            return self.name;
        }
    }

    GLOBAL['ex3'] = new ex3('ex3');
}

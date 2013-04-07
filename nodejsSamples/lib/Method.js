
Function.prototype.method = function (name, func) {
    this.prototype[name] = func;
    return this;
}

String.prototype.toBytes = function () {
  var bytes = [];
  for (var i = 0; i < this.length; ++i) {
      bytes.push(this.charCodeAt(i));
  }
  return bytes;
};

// reference the good parts : page 49
Function.method('inherits', function (Parent) {
    this.prototype = new Parent();
    return this;
});

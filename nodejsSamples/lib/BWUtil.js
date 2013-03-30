
module.exports = {
  type: function (obj) {
          return (obj === null) ? "null": typeof obj;
        },
  objectType: function (obj) {
          return Object.prototype.toString.call(obj);
        },
  isArray: function (obj) {
          return Object.prototype.toString.call(obj) === '[object Array]';
        }
}

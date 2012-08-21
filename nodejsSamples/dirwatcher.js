var watch = require('watch'),
util = require('util');

watch.watchTree('.', function (f, curr, prev) {
    if (typeof f == "object" && prev === null && curr === null) {
          // Finished walking the tree
          console.log("finish");
          } else if (prev === null) {
          // f is a new file
          console.log("new: " + f + ':' + util.inspect(curr));
          } else if (curr.nlink === 0) {
          // f was removed
          console.log("rm: " + f + ':' + util.inspect(curr));
          } else {
          // f was changed
          console.log("update: "  + f + ':' + util.inspect(curr));
          }
          })

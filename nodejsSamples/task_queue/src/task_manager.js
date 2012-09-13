define([],
    function(){
        return function () {
            var self = this;
            var task_queue = [];

            this.addTask = function (callback, args) {
                if (!callback)
                    return false;
                var task = { args: args, callback: callback }
                task_queue.push(task);
                return true;
            }

            this.run = function() {
                while (task_queue.length > 0) {
                    var task = task_queue.shift();
                    task.callback(task.args);
                }
            }

            var watchInterval = 1000;
            var watchTimer;
            this.stopWatch = function () {
                if (watchTimer) {
                    clearInterval(watchTimer)
                    watchTimer = null;
                }
            }

            this.watch = function () {
                self.stopWatch();
                watchTimer = setInterval(function () {
                    self.run();
                }, watchInterval);
            }
        }

    });

define(["task_manager"],
    function(task_manager){
        return function () {
                var manager = new task_manager();
                var max = 9;
                function echo_msg (data) {
                    var d = new Date();
                    console.log(d + ":echo " + data);
                    if (data == max) {
                        manager.stopWatch();
                    }
                }

                manager.addTask(echo_msg, 0);

                manager.watch();

                var num = 0;
                for (var i = 1; i < max+1 ; i++) {
                    setTimeout(function () {
                        num++;
                        manager.addTask(echo_msg, num);
                    }, 500 * i);
                }
            }
    });

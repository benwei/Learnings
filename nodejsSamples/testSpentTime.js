var SpentTime = require('./lib/SpentTime');

var st = new SpentTime();

setTimeout(function () {
    console.log("test 1 in " + st.diff() + 'ms');
    setTimeout(function () {
        console.log("test 2 in " + st.diff() + 'ms');
        st.reset();
        setTimeout(function () {
            console.log("after reset(), test 3 in " + st.diff() + 'ms');
            st.reset();
            setTimeout(function () {
                // for more accurately, store diff in variable, because of console.log need time ?;
                var d = st.diff();
                console.log("after reset() and variable, test 4 in " + d + 'ms');
            }, 15);
        }, 15);
    }, 20);
}, 10);


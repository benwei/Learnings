// http://www.youtube.com/watch?v=F6k8lTrAE2g&feature=youtube_gdata
// Ryan Google Teck Talks

var spawn = require('child_process').spawn;

cat = spawn('cat');

cat.stdin.write('hello\n');

setTimeout(function () {
    cat.stdin.end('bye\n');
}, 1000);

cat.stdout.on('data', function (d) {
    console.log(''+ d);
});

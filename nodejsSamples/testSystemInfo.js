var util = require('util');
console.log("platform: " + process.platform);

console.log("memory usage: " + util.inspect(process.memoryUsage()));
// output sample on win xp + cygwin,
// --- begin log ---
// platform: win32
// memory usage: { rss: 9220096, heapTotal: 2669184, heapUsed: 1457820 }
// /* heapTotal and heapUsed refer to V8's memory usage. */
// --- end log ---

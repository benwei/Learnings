#!/usr/bin/env node

// sample from Ryan Dahl (http://four.livejournal.com/)

net = require('net');
a = process.argv.slice(2);
if (!a.length) {
   console.error("telnet.js port [ host=localhost ]");
   process.exit(1);
}

s = require('net').Stream();
s.connect.apply(s, a);
s.pipe(process.stdout);
stdin = process.openStdin()
stdin.pipe(s);

s.on('end', function () {
       stdin.destroy();
});


#!/usr/bin/env node

// sample from Ryan Dahl (http://four.livejournal.com/)
require('net').Server(function (s) { s.pipe(s); }).listen(8000);


console.time('100-elements');
a = 1; b = 2;
for (var i = 0; i < 10000; i++) {
   a = b + a * b;
}
console.timeEnd('100-elements');

loopCount = 4;
if (process.argv.length > 2)
loopCount=process.argv[2];


function padLineNo(n, leading) {
    if (n < 10) {
        return leading + n.toString();
    }
    return n.toString();
}

i = 0;
while (i < loopCount) {
console.log(padLineNo(i+1, ' ') + ': 4');
i++;
}

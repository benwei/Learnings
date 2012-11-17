// reference in http://nodejs.org/api/readline.html

var readline = require('readline');
rl = readline.createInterface(process.stdin, process.stdout);
rl.setPrompt('B> ');
rl.prompt();

rl.on('line', function(line) {
    switch(line.trim()) {
        case 'help':
            console.log('exit - terminate this program');
            break;
        case 'exit':
            console.log('bye!');
            rl.close();
            break;
        default:
            console.log('Say what? I might have heard `' + line.trim() + '`');
            break;
    }
    rl.prompt();
}).on('close', function() {
    console.log('Have a great day!');
    process.exit(0);
});

rl.on('SIGINT', function() {
    // free resource or close tasks in running gracefully.
    rl.question('Are you sure you want to exit?(Please type [y|Y]) ', function(answer) {
        if (answer.match(/^y(es)?$/i) ||
            answer.match(/^Y(ES)?$/i)
        ) rl.pause()
    });
});


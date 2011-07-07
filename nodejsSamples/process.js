
process.stdin.resume();
flagSIGINT = false;

function handlingEvent()
{
    if (flagSIGINT)
        process.exit(0);
    else 
        setTimeout(handlingEvent, 2000);
}

process.on('SIGINT', function () {
  console.log('Got SIGINT. Wait 2 seconds for process termination.');
  handlingEvent();
  flagSIGINT = true;  
});


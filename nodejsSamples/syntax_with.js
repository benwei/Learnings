

var a = {
 level1: 
  { level2:
    { name: 'Sue', status: 'offline' }
  }
}

with(a.level1.level2) {
  console.log(name);
  console.log(status);
}

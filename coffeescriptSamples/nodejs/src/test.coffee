
foo = require('./foo')

sum = 0

test = (a, b) ->
  return a+b

sum = test(1, 3)
console.log('sum=' + sum)
console.log('foo(1,4)=' + foo(1,4))

console.log('create file')


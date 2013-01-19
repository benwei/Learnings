util = require('util')
foo = require('./foo')
myextend = require('./myextend')

sum = 0

test = (a, b) ->
  return a+b

sum = test 1, 3
console.log 'sum=' + sum
console.log 'foo(1,4)=' + util.inspect(foo(1,4))

console.log 'test1'

numList0to9 = [0..9]
console.log 'num list [0..9] ==> ' + numList0to9
numList0to8 = [0...9]
console.log 'num list [0...9] ==> ' + numList0to8
nameList = ['sue', 'john', 'amy']
console.log 'name list ==>' + nameList

myextend()

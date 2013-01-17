util = require('util')
foo = require('./foo')

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

# extend class

class human
  constructor: (name) ->
    @name = name
  setName: (name) ->
    @name = name

  getName: () ->
    @name

class techer extends human
  constructor: (name) ->
    super(name)
    @job = 'techer'
    @students = []

  addStudent: (name) ->
    @students.push(name)

  hasStudents: ->
    @students

  listStudents: ->
    console.log "#{@name} is a #{@job}. #{@name} teches #{@students}."

sue = new human('Sue')

console.log sue.getName()

john = new techer('John')
john.addStudent('Ming')
john.addStudent('Bob')

john.listStudents()


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

module.exports = ->
  sue = new human('Sue')

  console.log sue.getName()

  john = new techer('John')
  john.addStudent('Ming')
  john.addStudent('Bob')

  john.listStudents()
  0


class Greeter
attr_accessor :name
def initialize(name = "World")
  @name = name
end

def say_hi
puts "Hi #{@name.capitalize}!"
end

def say_bye
puts "Bye #{@name.capitalize}!"
end
end

h = Greeter.new("jobs")
h.say_hi
h.say_bye

h.name = "bob"
h.say_hi
h.say_bye


# Assignment:
number   = 42
opposite = true

# Conditions:
number = -42 if opposite

# Functions:
square = (x) -> x * x

# Arrays:
list = [1, 2, 3, 4, 5]

# Objects:
math =
  root:   Math.sqrt
  square: square
  cube:   (x) -> x * square x

# Splats:
race = (winner, runners...) ->
  data = ""
  for i in runners
    data += "|" + i 
  console.log winner, data

race "a","b", "c"

# Existence:
console.log "I knew it!" if elvis?

# Array comprehensions:
cubes = (math.cube num for num in list)

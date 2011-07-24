-- defines a factorial function (this line is a comment)
io.write([[enter a number:]])
io.flush()
-- a = read("*number") -- read a number
-- a = io.read("*number") -- read a number
l = io.read() -- read a line
n = tonumber(l) -- try to convert it to a number
if n == nil then
error(l.." is not a valid number")
end

print("number is "..n)

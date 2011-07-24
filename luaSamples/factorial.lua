-- defines a factorial function (this line is a comment)
function factorial (n)
	if n == 0 then
		return 1
	else 
		return n*factorial(n-1)
	end
end

function ifnilerror(m,l)
if m == nil then
error(l.." is not a valid number")
end
end

if #arg <= 1 then
error("mssing argv: <factorial count> <max repeat count>")
end
l = arg[1]
n = tonumber(l)
ifnilerror(n,l)
l = arg[2]
repeatCount = tonumber(l)
ifnilerror(repeatCount,l)

start=os.clock()
i = 0
sum = 0
while (i < repeatCount) do
sum = factorial(n)
i=i+1
end

diff=os.clock() - start
print("Sum="..sum .. ", repeat sum:" .. repeatCount ..", escaped time:"..diff)

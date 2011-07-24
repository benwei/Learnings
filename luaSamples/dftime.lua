print("argument count="..#arg)
if #arg == 0 then
error("mssing argv: <factorial count>")
end

print("count is "..arg[1])
max=tonumber(arg[1])

begin=os.clock()
print("begin time:" .. os.time())

for i=1,max do
b = factorial(13)
end
print("f(13)="..b)

a=os.clock() - begin
print("end time:" .. os.time())
print("diff clock:" .. a);

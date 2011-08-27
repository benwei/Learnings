a = Array.new(2, Hash.new)
b = Array.new(2){ Hash.new }


a[0]['a'] = '0a'
a[1]['b'] = '1b'

b[0]['a'] = '0a'
b[1]['b'] = '1b'
puts "a Array:"

def dumpArray(x) 
	for i in x do 
	puts "#{i}"
	end
end

dumpArray(a)

puts "b Array:"
dumpArray(b)

c = Array.new(10) {|i| i+1}

puts "c Array in turns:"
dumpArray(c)
# output string with , split-char
puts "c Array show numbers with split-char ','"
puts c * ","
d = c * 2

puts "C Array * 2: "
dumpArray(d * ";")

puts (d[0,9] * '-')
puts (d[-5,5] * '+')
puts (d[20])
puts ("count=" + String(d[20,21].count))

e = [48, 49, 50]
puts e.pack("ccc")

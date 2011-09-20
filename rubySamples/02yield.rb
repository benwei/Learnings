
def test_yield(n)
	sum=0
	i=1

	while(i <= n)
		sum +=i
		yield sum
		i+=1
	end
end

test_yield(10) do |result|
	puts result
	end

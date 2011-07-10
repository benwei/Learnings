
class MegaGreeter
attr_accessor :names
def initialize(names = "World")
  @names = names
end

def say_hi
	if @names.nil?
	puts "..."
	elsif @names.respond_to?("each")

		@names.each do |name|
		puts "Hi #{name.capitalize}!"
		end
	else
		puts "Hi #{@names.capitalize}!"
	end
end

def say_bye
	if @names.nil?
	puts "..."
	elsif @names.respond_to?("join")
		puts "Bye #{@names.join(", ")}!"
	else
		puts "Bye #{@names.capitalize}!"
	end
end
end

# main
if __FILE__ == $0
	h = MegaGreeter.new()
	h.say_hi
	h.say_bye

	h.names = "bob"
	h.say_hi
	h.say_bye

	h.names = ["bob", "jobs", "sue"]
	h.say_hi
	h.say_bye

	h.names = nil
	h.say_hi
	h.say_bye
end

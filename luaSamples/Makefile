CHECKS= runByInterpreter runbyByteCode
binFile=./bin/factorial
repeatCount=10000000
num=13
all: checks

$(binFile): factorial.lua
	mkdir -p ./bin
	# generate bytecode
	luac -o $(binFile) factorial.lua

runByInterpreter:
	lua factorial.lua $(num) $(repeatCount)

runbyByteCode: $(binFile)
	lua $(binFile) $(num) $(repeatCount)

checks: $(CHECKS)

clean:
	rm -f $(binFile)
	rm -rf ./bin

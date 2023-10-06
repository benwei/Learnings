
SWIFT_RUN = @echo run [$<]; swift

TARGET=output/hello_swift

all: preconfig run

preconfig: output

output:
	mkdir -p output

output/%.o: %.swift
	swiftc -emit-object -o $@ $<

$(TARGET): output/hello_swift.o
	swiftc -o $@ $<

run: $(TARGET)
	./$<

runs: hello_swift.swift
	$(SWIFT_RUN) $<

clean:
	rm -rf output

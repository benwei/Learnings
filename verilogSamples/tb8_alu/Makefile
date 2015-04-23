
VFILES=alu.v main.v
TARGET=alu_test
all: $(TARGET)
$(TARGET): $(VFILES)
	iverilog -o $@ $^

run: $(TARGET)
	./$^

clean:
	rm -f $(TARGET)

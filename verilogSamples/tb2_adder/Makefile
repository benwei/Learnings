VC = iverilog
VCFLAGS = -I. -s adder_tb
FILES = adder.v adder_tb.v
TARGET= adder_tb

all: $(TARGET)

$(TARGET): $(FILES)
	$(VC) $(VCFLAGS) -o $(TARGET) $(FILES)

run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET) 

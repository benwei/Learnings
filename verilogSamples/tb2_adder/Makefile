VC = iverilog
VCFLAGS = -I. -s adder_tb
FILES = adder.v adder_tb.v
TARGET= adder_tb

all: $(TARGET)

$(TARGET): $(FILES)
	$(VC) $(VCFLAGS) -o $(TARGET) $(FILES)

run: $(TARGET)
	./$(TARGET)

wave: run
	gtkwave tb2.gtkw

clean:
	rm -f $(TARGET) *.vcd

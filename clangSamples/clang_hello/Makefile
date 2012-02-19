TARGET=hello
CLANG=clang
LLI=lli-2.8
LLC=llc-2.8
LLDIS=llvm-dis-2.8


all: $(TARGET) journey
.c.o:
	$(CLANG) -c $< -o $@

$(TARGET): % : %.o
	$(CLANG) $^ -o $@

$(TARGET).bc : $(TARGET).c
	# generate IR 
	# IR is small, simple, easy to understand and is well defined.
	$(CLANG) -O3 -emit-llvm $^ -c -o $@
	# run as Just-In-Time Compiler 
	$(LLI) $@

$(TARGET).dis : $(TARGET).bc
	# deassemble BitCode
	$(LLDIS) < $^ > $@

$(TARGET).s : $(TARGET).bc
	# generate .s from .bc
	$(LLC) $< -o $@

journey: $(TARGET).s $(TARGET).dis

clean:
	#rm -f *.o *.s *.dis *.bc $(TARGET)
	rm -f *.o  $(TARGET)

VCFLAGS = -I. -s cmpbyte_tb

### reference build option
## make USE_REG=1

ifneq ($(USE_REG),1)
VCFLAGS += -DWIRE_PART
endif

FILES = cmpbyte.v cmpbyte_tb.v
TARGET= cmpbyte_tb
GTKW  = tb.gtkw
include ../Makefile.verilog

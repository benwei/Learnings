VCFLAGS = -I. -s twomux_tb

### reference build option
## make USE_REG=1

ifneq ($(USE_REG),1)
VCFLAGS += -DWIRE_PART
endif

FILES = twomux.v twomux_tb.v
TARGET= twomux_tb
GTKW  = tb.gtkw
include ../Makefile.verilog

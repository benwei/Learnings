# reference option -b from http://stackoverflow.com/questions/11317269/how-to-compile-lua-scripts-into-a-single-executable-while-still-gaining-the-fas

luajit=$(shell which luajit)
INCS+= -I/usr/include/lua5.1
CFLAGS = -O2 -Wall -Wl,-E $(INCS)

LDFLAGS = -lluajit-5.1 -lm -ldl

LUA_FILES = main.lua hello.lua
LUAJIT_OUTPUT = lua_o
LUA_OBJS = $(addprefix $(LUAJIT_OUTPUT)/,$(LUA_FILES:.lua=.o))

COBJS = loader.o
OBJS = $(addprefix build/,$(COBJS))

current_dir = $(shell pwd)
PB_LUAJIT=prebuilt/LuaJIT-2.0.0/src/luajit 
LUAJIT_ROOT_DIR=prebuilt/libs/LuaJIT
LUAJIT=$(LUAJIT_ROOT_DIR)/bin/luajit 
LUAJIT_DIRS=$(current_dir)/$(LUAJIT_ROOT_DIR)/share/luajit-2.0.0/jit/?.lua
#prebuilt-libs

define jit-inst
	cd prebuilt/LuaJIT-2.0.0/ ; \
	make install PREFIX=$(current_dir)/prebuilt/libs/LuaJIT
endef

all: pre-build $(LUAJIT) mytest

pre-build:
	mkdir -p build $(LUAJIT_OUTPUT)

$(LUAJIT):
	@if [ -n "$(luajit)" ]; then \
		echo "found $(luajit)" ; \
		exit 0; \
	else \
		echo "luajit not found, try to download and compile it"; \
	fi
	mkdir -p prebuilt; \
	cd prebuilt; \
	if [ ! -f "LuaJIT-2.0.0.tar.gz" ]; then \
		wget -O LuaJIT-2.0.0.tar.gz http://luajit.org/download/LuaJIT-2.0.0.tar.gz ; \
	fi ; \
	if md5sum LuaJIT-2.0.0.tar.gz|cut -d' ' -f1 = "97a2b87cc0490784f54b64cfb3b8f5ad" ; then \
		echo "md5 is verified." ; \
	fi ; \
	if [ ! -d "LuaJIT-2.0.0" ]; then \
		tar zxvf LuaJIT-2.0.0.tar.gz ; \
	fi ; \
	if [ ! -f "$(PB_LUAJIT)" ]; then \
	cd LuaJIT-2.0.0/ ; make ;  \
	fi
	$(call jit-inst)

luajit_pkg_path: $(LUAJIT)
	# http://stackoverflow.com/questions/6760199/luajit-require-module-error
	# pass environment LUA_PATH the change the package.path
	$(LUAJIT) -e "print(package.path)"

$(LUAJIT_OUTPUT)/%.o: %.lua
	luajit -b $< $@ 

lua_objs.a: $(LUA_OBJS)
	ar rcus $@ $^

build/%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

mytest: lua_objs.a $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

run: mytest
	LD_LIBRARY_PATH=/usr/local/lib/ $(LEADING) ./mytest $(ARGS)

hellolua.h: hello.lua
	$(LUAJIT) -b $< $@

clean:
	rm -rf $(LUAJIT_OUTPUT) *.o mytest *.a build hellolua.h

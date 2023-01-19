# for testing rust build flow
OUTPUT_DIR =./output
APP_SRCS  += hello.rs
APP_PATHNAME=$(OUTPUT_DIR)/hello
REL_APP_PATHNAME=$(OUTPUT_DIR)/hello_stripped

# utils
RUSTC      = rustc
UTIL_CP    = cp
UTIL_FILE  = file
UTIL_STRIP = strip

all: prebuild $(APP_PATHNAME)

prebuild: $(OUTPUT_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(APP_PATHNAME): $(APP_SRCS)
	$(RUSTC) $^ -o $@

runit: $(APP_PATHNAME)
	$(UTIL_FILE) $(APP_PATHNAME)
	$(APP_PATHNAME)
	$(UTIL_CP) $(APP_PATHNAME) $(REL_APP_PATHNAME)
	$(UTIL_STRIP) $(REL_APP_PATHNAME)
	$(UTIL_FILE) $(REL_APP_PATHNAME)
	$(REL_APP_PATHNAME)

clean:
	rm -f $(APP_PATHNAME)

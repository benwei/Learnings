# the generice purpose for sample make script by ben@staros.mobi

depends ?= $(OBJS:.o=.p)

.c.o:
	$(CC) -MMD -MF ${@:.o=.p} -c $(CFLAGS) -o $@ $<

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJS)
ifeq ($(CXXFILES),)
	$(CC) -o $@ $^ $(LDFLAGS) 
else
	$(CXX) -o $@ $^ $(LDFLAGS) 
endif

run: $(OBJS) $(TARGET)
	$(RUNENV) ./$(TARGET) $(RUN_ARGS)

clean:
	@rm -f $(TARGET) *.o $(depends) $(CLEAN_FILES)

-include $(depends)

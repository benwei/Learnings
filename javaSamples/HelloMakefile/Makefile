SRCPATH=.
JAVA_FILES=$(SRCPATH)/HelloWorld.java $(SRCPATH)/HelloWorld2.java
TARGETS=$(JAVA_FILES:.java=.class)

all: $(TARGETS)

$(SRCPATH)/%.class: $(SRCPATH)/%.java
	@echo "building [$@]" ; \
	javac -cp . $<

run: $(TARGETS)
	@#java will run HelloWorld.class by search classpath in $(SRCPATH)
	@cd $(SRCPATH) ; \
	for i in $(TARGETS) ; do \
	target="`basename $${i%.class}`" ; \
	echo "run $$target ---> "; \
	java -cp $(SRCPATH) $$target ; \
	done

clean:
	rm -f $(SRCPATH)/*.class

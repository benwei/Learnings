SRCPATH=./
JFILE=$(SRCPATH)/HelloWorld.java
TARGET=$(SRCPATH)/HelloWorld.class

all: $(TARGET)

$(TARGET): $(JFILE)
	javac -cp . $< 

run: $(TARGET)
	java -cp $(SRCPATH) HelloWorld

clean:
	rm -f $(SRCPATH)/*.class

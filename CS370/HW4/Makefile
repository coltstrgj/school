#this is my makefile
#it will make both files from their respective .c file normally
#make clean will allow you to quickly remove all of the compiled files
.java.class:
	javac $*.java

CLASSES = \
        Producer.java \
        Consumer.java \
        ProducerConsumer.java \
        BoundedBuffer.java 

default: classes

classes: $(CLASSES:.java=.class)

Producer.class: Producer.java
	javac Producer.java
Consumer.class: Consumer.java
	javac Consumer.java
BoundedBuffer.class: BoundedBuffer.java
	javac BoundedBuffer.java
ProducerConsumer.class: ProducerConsumer.java
	javac ProducerConsumer.java

clean:
	rm -f *.class

# CXXFLAGS=-Wall -Wextra -ansi -pedantic

linked: main.o ll.o
	g++ $(CXXFLAGS) main.o ll.o -o linked

main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc

ll.o: ll.cc ll.h
	g++ $(CXXFLAGS) -c ll.cc

clean:
	-rm -f small *.o

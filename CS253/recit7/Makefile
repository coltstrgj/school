CXXFLAGS=-Wall -Wextra -ansi -pedantic

#simple: simple.cc
#	g++ $(CXXFLAGS) simple.cc -o simple `pkg-config gtkmm-3.0 --cflags --libs`
main: main.o helloworld.o
	g++ $(CXXFLAGS) main.o helloworld.o -o simplen `pkg-config gtkmm-3.0 --cflags --libs`


main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc  `pkg-config gtkmm-3.0 --cflags --libs`


helloworld.o: helloworld.cc helloworld.h
	g++ $(CXXFLAGS) -c helloworld.cc  `pkg-config gtkmm-3.0 --cflags --libs`





clean:
	-rm -f main *.o

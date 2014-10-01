CXXFLAGS=-Wall -Wextra -ansi -pedantic

#simple: simple.cc
#	g++ $(CXXFLAGS) simple.cc -o simple `pkg-config gtkmm-3.0 --cflags --libs`
main: main.o hangman.o
	g++ $(CXXFLAGS) main.o hangman.o -o simplen `pkg-config gtkmm-3.0 --cflags --libs`


main.o: main.cc
	g++ $(CXXFLAGS) -c main.cc  `pkg-config gtkmm-3.0 --cflags --libs`


hangman.o: hangman.cc hangman.h
	g++ $(CXXFLAGS) -c hangman.cc  `pkg-config gtkmm-3.0 --cflags --libs`

word.o: word.cc word.h
	g++ $(CXXFLAGS) -c word.cc `pkg-config gtkmm-3.0 --cflags --libs`


clean:
	-rm -f main *.o

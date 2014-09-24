CXXFLAGS=-Wall -Wextra -pedantic
COMPILER=clang++

pnum: main.o PNum.o
	$(COMPILER) $(CXXFLAGS) main.o PNum.o -o pnum
main.o: main.cc
	$(COMPILER) $(CXXFLAGS) -c main.cc

PNum.o: PNum.cc PNum.h
	$(COMPILER) $(CXXFLAGS) -c PNum.cc

clean:
	-rm -f pnum *.0

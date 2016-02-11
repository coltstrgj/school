COMPILER=g++
CXXFLAGS=-std=c++11 #-Wall -Wextra

main: cipher.o 
	$(COMPILER) $(CXXFLAGS) cipher.o -o cipher

cipher.o: cipher.cpp
	$(COMPILER) $(CXXFLAGS) -c cipher.cpp 

clean:
	rm -f cipher *.o

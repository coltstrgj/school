#this is my makefile
#it will make both files from their respective .c file normally
#make clean will allow you to quickly remove all of the compiled files
CXXFLAGS=-std=c11 -Wall -Wextra -pedantic

all: Darien_Colt_Coordinator.out Darien_Colt_Checker.out 

Darien_Colt_Checker.out: Darien_Colt_Checker.c
	echo $(Print) && gcc $(CXXFLAGS) -o Darien_Colt_Checker.out Darien_Colt_Checker.c #--------------------

Darien_Colt_Coordinator.out: Darien_Colt_Coordinator.c 
	echo $(Print) && gcc $(CXXFLAGS) -o  Darien_Colt_Coordinator.out Darien_Colt_Coordinator.c #--------------------

clean:
	-rm -f *.out

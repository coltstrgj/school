#this is my makefile
#it will make both files from their respective .c file normally
#make clean will allow you to quickly remove all of the compiled files

all: Darien_Colt_Coordinator.out Darien_Colt_Checker.out 

Darien_Colt_Checker.out: Darien_Colt_Checker.c
	gcc -o Darien_Colt_Checker.out Darien_Colt_Checker.c

Darien_Colt_Coordinator.out: Darien_Colt_Coordinator.c 
	gcc -o  Darien_Colt_Coordinator.out Darien_Colt_Coordinator.c

clean:
	-rm -f *.out

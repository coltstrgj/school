#this is my makefile
default: both
	//this will usually compile everything

both: Darien_Colt_Coordinator.out 
	gcc  -o Darien_Colt_Coordinator.out Darien_Colt_Coordinator.c Darien_Colt_Checker.out

Darien_Colt_Coordinator.out: 
	gcc -o  Darien_Colt_Coordinator.out Darien_Colt_Coordinator.c


Darien_Colt_Checker.out: 
	gcc -o Darien_Colt_Checker.out Darien_Colt_Checker.c


clean:
	-rm -f *.out

Darien_Colt_Coordinator.c
    This file takes 5 arguments. the divisor, and 5 dividends.
    This file is the "parent" program. It will fork and then exec Darien_Colt_Checker
    This program also outputs the value calculated by its child (1 represents divisible, 0 not divisible)
    It will retrieve the output from a shared memory address which it shared over a pipe with Darien_Colt_Checker.out
Darien_Colt_Checker.c
    This file is the source for a program that takes 3 arguments, the pipe, the divisor and dividend. 
    It will then calculate whether the dividend is divisible by the divisor
    the file will write 1 to a shared memory if the numbers are divisible, 0 otherwise.

Makefile
    This is the file that will allow you wo quickly compile and remove compiled code. You will not have to 
    type gcc and the output names anymore. It uses all of the flags that I normally use.

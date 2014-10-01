Darien_Colt_Coordinator.c
    This file takes 5 arguments. the divisor, and 5 dividends.
    This file is the "parent" program. It will fork and then exec Darien_Colt_Checker
    This program also outputs the return value from each child as well as the PID of itself and the children.
Darien_Colt_Checker.c
    This file is the source for a program that takes 2 arguments, the divisor and dividend. It will then calculate whether the dividend is divisible by the divisor
    the file will return 0 if they are not divisible and 1 if they are.

Makefile
    This is the file that will allow you wo quickly compile and remove compiled code. You will not have to type gcc and the output names anymore.

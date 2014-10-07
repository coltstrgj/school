#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int coordinate(char* divisor, char* dividend){
    int cpid, w;//TODO create a 2d array that stores PID Pipe, and return
    int status;
    cpid=fork();
    if (cpid == -1) {
        perror("fork");
          exit(EXIT_FAILURE);
    }
    if(cpid==0){
        //is child
        if (-1 == execl("./Darien_Colt_Checker.out", "Darien_Colt_Checker.out", divisor, dividend, NULL)){
            perror("execlp() failed");//this means it is broken, because it should never reach this code unless it fails to execl
            return 0;
        }
    }else{
        //is parent
        printf("Coordinator: forked process with ID: %i\n", cpid);
        printf("Coordinator: waiting for process [%i]\n", cpid);   
        w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);//the following is shamelessly stolen from man pages
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        printf("Coordinator: child process %i returned %i.\n", cpid,  WEXITSTATUS(status));//grabs the exit status of the previous child, and outputs it before returning to my awful "loop" in main
        return 1;
    }
}
int main(int argc, char* argv[]){
    if(argc!=6){
        printf("Bad input:\nUsage: 'coordinator divisor dividend dividend dividend dividend\n");
        return 0;
    }
    //the following loop calls the method above and creates child processes
//  for(int i=0; i<4; i++){
//      coordinate(argv[1],argv[i+2]); 
//  }

        coordinate(argv[1],argv[2]); 
}


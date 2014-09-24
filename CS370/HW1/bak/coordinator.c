#include <stdio.h>
//#include <sys/types.h>
//#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int coordinate(char* divisor, char* dividend){
    pid_t cpid, w;
    int status;
    cpid=fork();
    if (cpid == -1) {
        perror("fork");
          exit(EXIT_FAILURE);
    }

    if(cpid==0){
        //is child
        //printf("child launched %i\n", getpid());
        if (-1 == execlp("Darien_Colt_Checker.out", "Darien_Colt_Checker.out", divisor, dividend, NULL)){
            perror("execlp() failed");
            return 0;
        }else{
            printf("it worked and somehow came back?");
        }
        return 1;
    }else{
        //is parent
        printf("Coordinator: forked process with ID: %i\n", cpid);
        printf("Coordinator: waiting for process [%i]\n", cpid);   
        w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
            if (w == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            asdfasdf
        printf("Coordinator: child process %i returned %i\n", cpid,  WEXITSTATUS(status));   
        return 1;
    }

}
int main(int argc, char* argv[]){

    if(argc!=6){

        printf("Bad input:\nUsage: 'coordinator divisor dividend dividend dividend dividend\n");
        return 0;
    }
    coordinate(argv[1],argv[2]); 
    coordinate(argv[1],argv[3]); 
    coordinate(argv[1],argv[4]); 
    coordinate(argv[1],argv[5]); 
    printf("Coordinator: exiting\n");    
    /*for(int i=0; i<4; i++){
        coordinate(argv[1],argv[i+2]); 
    }*/
} 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int coordinate(char* divisor, char* dividend){
    int cpid, w;//TODO create a 2d array that stores PID Pipe, and return
    int status;

    //there will be 4 children, so we will keep a 2dimensional array where 
    //i is the child number [i][0] is the pipe for child i and [i][1] is the return value 
    int childTrack[4][2];
    //for(int i=0; i<4; i++){
    int fildes[2];
    //childTrack[i]=fildes;
    const int BSIZE = 100;//this will be used so that parent can send the shared memory info to child
    char buf[BSIZE];
    ssize_t nbytes;
    //create the pipe that parent will use to send shared memory info to child
    status = pipe(fildes);
    if (status==-1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    //fork the programs and decide whether the instance is the parent or child
    //switch (fork()) {
    //case −1: /* Handle error */
    //    break;

    //case 0:  /* Child - reads from pipe */
    //    close(fildes[1]);                       /* Write end is unused */
    //    nbytes = read(fildes[0], buf, BSIZE);   /* Get data from pipe */
    //    /* At this point, a further read would see end of file ... */
    //    close(fildes[0]);                       /* Finished with pipe */
    //    exit(EXIT_SUCCESS);

    //default:  /* Parent - writes to pipe */
    //    close(fildes[0]);                       /* Read end is unused */
    //    write(fildes[1], "Hello world\n", 12);  /* Write data on pipe */
    //    close(fildes[1]);                       /* Child will see EOF */
    //    exit(EXIT_SUCCESS);
    //}
    cpid=fork();
    if (cpid == -1) {//neither parent or child
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(cpid==0){//is child
        //the child will get the shared memory information from the pipe 
        close(fildes[1]);/* Write end is unused */
        //    nbytes = read(fildes[0], buf, BSIZE);   /* Get data from pipe */
        //    /* At this point, a further read would see end of file ... */
        //    close(fildes[0]);                       /* Finished with pipe */
        //    exit(EXIT_SUCCESS);
        if (-1 == execl("./Darien_Colt_Checker.out", "Darien_Colt_Checker.out", divisor, dividend, NULL)){
            perror("execlp() failed");//this means it is broken, because it should never reach this code unless it fails to execl
            return 0;
        }
    }else{//is parent
        //the parent needs to create shared memory and send the info to the child
        printf("Coordinator: forked process with ID: %i\n", cpid);
        //default:  /* Parent - writes to pipe */
        close(fildes[0]);                       /* Read end is unused */
        //    write(fildes[1], "Hello world\n", 12);  /* Write data on pipe */
        //    close(fildes[1]);                       /* Child will see EOF */
        //    exit(EXIT_SUCCESS);
        //printf("Coordinator: waiting for process [%i]\n", cpid);   
        w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);//the following is shamelessly stolen from man pages
        if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        printf("Coordinator: child process %i returned %i.\n", cpid,  WEXITSTATUS(status));
        //grabs the exit status of the previous child, and outputs it before returning to my awful "loop" in main
        return 1;
    }
    //}
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
//the following is from the man pages
//int fildes[2];
//const int BSIZE = 100;
//char buf[BSIZE];
//ssize_t nbytes;
//int status;

//status = pipe(fildes);
//if (status == −1 ) {
//    /* an error occurred */
//    ...
//}

//switch (fork()) {
//case −1: /* Handle error */
//    break;

//case 0:  /* Child - reads from pipe */
//    close(fildes[1]);                       /* Write end is unused */
//    nbytes = read(fildes[0], buf, BSIZE);   /* Get data from pipe */
//    /* At this point, a further read would see end of file ... */
//    close(fildes[0]);                       /* Finished with pipe */
//    exit(EXIT_SUCCESS);

//default:  /* Parent - writes to pipe */
//    close(fildes[0]);                       /* Read end is unused */
//    write(fildes[1], "Hello world\n", 12);  /* Write data on pipe */
//    close(fildes[1]);                       /* Child will see EOF */
//    exit(EXIT_SUCCESS);
//}


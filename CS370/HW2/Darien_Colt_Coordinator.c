#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char* argv[]){
    if(argc!=6){
        printf("Bad input:\nUsage: 'coordinator divisor dividend dividend dividend dividend\n");
        return 0;
    }
    //..array with PID of child, shm info, return value

    for(int i=0; i<4; i++){
        ///..fork
        int cpid, w;//TODO create a 2d array that stores PID Pipe, and return
        int status;
        int fildes[2];
        //actual work from here down
        status = pipe(fildes);
        if (status==-1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        cpid=fork();
        if (cpid == -1) {//neither parent or child
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(cpid==0){
            /* Child - reads from pipe */
            close(fildes[1]);/* Write end is unused */
            char pipeName[BUFSIZ];
            snprintf(pipeName, sizeof(pipeName), "%i", fildes[0]);
            //printf("fildes: %i, pipeName: %s\n\n", fildes[0], fildes);
            if (-1 == execl("./Darien_Colt_Checker.out", "Darien_Colt_Checker.out", pipeName, argv[1], argv[i+2], NULL)){
                perror("execlp() failed");//this means it is broken, because it should never reach this code unless it fails to execl
                return 0;
            }
        }else{//is parent
            //the parent needs to create shared memory and send the info to the child
            printf("Coordinator: forked process with ID: %i\n", cpid);
            //..Should create shared memory 
            key_t key = i;                    /* key to be passed to shmget() */
            /*"child" and i are added to get a base key because I have no idea what I should actually do here*/ 
            int shmflg;                                 /* shmflg to be passed to shmget() */ 
            int shmid;                                  /* return value from shmget() */ 
            int size;                                   /* size to be passed to shmget() */  
            shmid = shmget(key, 4, IPC_CREAT | 0644);
            ///////printf("shmflg:%i size:%i shmid:%i \n",shmflg, size, shmid);
            //..Add relevant info to shared mem array TODO
            //..create pipe and send it relevant info on shared memory TODO 
            /* Parent - writes to pipe */
            //actually creates the pipe

            char shm_name[BUFSIZ];
            snprintf(shm_name, sizeof(shm_name), "%i %i", shmid, i);
            close(fildes[0]);                           /* Read end is unused */
            int nbytes = write(fildes[1], shm_name, 6);    /* Write data on pipe */
            close(fildes[1]);                           /* Child will see EOF */
            printf("Coordinator: wrote shm ID %i to pipe (%i bytes)\n", shmid,nbytes);
            //Coordinator: wrote shm ID 4063308 to pipe (4 bytes) TODO

        }

    }
    /*
       for(int i=0; i<4; i++){
//..wait for the child TODO
int w, status;
////////////wait for the cpid stored in the array
w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
if (w == -1) {
perror("waitpid");
exit(EXIT_FAILURE);
}
printf("Coordinator: child process %i returned %i.\n", cpid,  WEXITSTATUS(status));
//grabs the exit status of the previous child, and outputs it before returning to my awful "loop" in main
return 1;
//..read the info from shared memory TODO
}*/
while(0<1){;}
return 1;
}

























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
    int child_array[4][2];//[i][0] is the PID, [i][1] is the shmid
    //..array with PID of child, shm info, return value
    for(int i=0; i<4; i++){
        ///..fork
        int cpid;
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
            close(fildes[0]);                           /* Read end is unused */
            child_array[i][0]=cpid;
            //the parent needs to create shared memory and send the info to the child
            printf("Coordinator: forked process with ID: %i\n", cpid);
            //..Should create shared memory 
            key_t key = i;                    /* key to be passed to shmget() */
            /*"child" and i are added to get a base key because I have no idea what I should actually do here*/ 
            int shmid;                                  /* return value from shmget() */ 
            int size=4;                                 /* size to be passed to shmget() 1 */  
            shmid = shmget(key, size, IPC_CREAT | 0644);
            child_array[i][1]=shmid;//save the id to the array for later use
            ///////printf("shmflg:%i size:%i shmid:%i \n",shmflg, size, shmid);
            //..Add relevant info to shared mem array TODO
            /* Parent - writes to pipe */
            //actually creates the pipe

            char shm_name[BUFSIZ];
            snprintf(shm_name, sizeof(shm_name), "%i %i", shmid, i);
            int nbytes = write(fildes[1], shm_name, 7);    /* Write data on pipe */
            close(fildes[1]);                           /* Child will see EOF */
            printf("Coordinator: wrote shm ID %i to pipe (%i bytes)\n", shmid,nbytes);

        }//end of parent

    }
    //wait for all of the processes and get all the returns
    for(int i=0; i<4; i++){
        int w, status;
        ////////////wait for the cpid stored in the array
        w = waitpid(child_array[i][0], &status, WUNTRACED | WCONTINUED);
        if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        char *ans=shmat(child_array[i][1],NULL , 0);
        int ans_int=atoi(ans);
        char divis[BUFSIZ];
        if(ans_int){
            snprintf(divis, sizeof(divis), "is divisible");
        }else{
            snprintf(divis, sizeof(divis), "is not divisible");
        }

        printf("Coordinator: result %i read from shared memory: %s %s by %s.\n", ans_int, argv[i+2], divis, argv[1]);
        //..read the info from shared memory TODO
        //Coordinator: result 1 read from shared memory: 3 is divisible by 3.
        //Coordinator: waiting on child process ID 25497...
    }
    return 1;
}

























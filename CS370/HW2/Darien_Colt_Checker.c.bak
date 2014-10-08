#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

int divide(int divisor, int dividend){
    if((dividend % divisor)==0){
        //was divisable (true)
        printf("Checker process [%i]: %i *IS* divisable by %i.\n", getpid(), dividend, divisor);
        return 1;
    }else{
        printf("Checker process [%i]: %i *IS NOT* divisable by %i.\n", getpid(), dividend, divisor); 
        return 0;
    }

}
int main(int argc, char* argv[]){
    printf("Checker process [%i]: Starting.\n", getpid());
    //case 0:  /* Child - reads from pipe */
    const int BSIZE = 100;
    char buf[BSIZE];
    ssize_t nbytes;
    nbytes = read(atoi(argv[1]), buf, 100);   /* Get data from pipe */
    /* At this point, a further read would see end of file ... */
    close(atoi(argv[1]));                       /* Finished with pipe */
    //printf("Checker process [%i]: got %s\n", getpid(), buf);
    int shmid=(atoi(buf));
    printf("Checker process [%i]: read %i bytes containing shm ID %s\n", getpid(), nbytes, buf);
    char *ans=shmat(shmid,NULL , 0);
    int is_divis=divide(atoi(argv[2]), atoi(argv[3]));
    snprintf(ans, sizeof(ans), "%i", is_divis);
    //do I detach?
    printf("Checker process [%i]: wrote result (%i) to shared memory.\n", getpid(), is_divis);
    return 1;
    //    exit(EXIT_SUCCESS);
}

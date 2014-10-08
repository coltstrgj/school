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
//
// shm-client - client program to demonstrate shared memory.
///

//include <sys/types.h>
//include <sys/ipc.h>
//include <sys/shm.h>
//include <stdio.h>

//define SHMSZ     27

//  main()
//  {
//      int shmid;
//      key_t key;
//      char *shm, *s;

//      /*
//       * We need to get the segment named
//       * "5678", created by the server.
//       */
//      key = 5678;

//      /*
//       * Locate the segment.
//       */
//      if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
//          perror("shmget");
//          exit(1);
//      }

//      /*
//       * Now we attach the segment to our data space.
//       */
//      if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
//          perror("shmat");
//          exit(1);
//      }

//      /*
//       * Now read what the server put in the memory.
//       */
//      for (s = shm; *s != NULL; s++)
//          putchar(*s);
//      putchar('\n');

//      /*
//       * Finally, change the first character of the 
//       * segment to '*', indicating we have read 
//       * the segment.
//       */
//      *shm = '*';

//      exit(0);
//  }


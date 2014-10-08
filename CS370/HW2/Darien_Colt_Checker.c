#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//int div(int divisor, int dividend){
//  if((dividend % divisor)==0){
//      //was divisable (true)
//      printf("Checker process [%i]: %i *IS* divisable by %i.\n", getpid(), dividend, divisor);
//      printf("Checker process [%i]: Returning 1.\n", getpid());
//      return 1;
//  }else{
//      printf("Checker process [%i]: %i *IS NOT* divisable by %i.\n", getpid(), dividend, divisor); 
//      printf("Checker process [%i]: Returning 0.\n", getpid());
//      return 0;
//  }

//}
int main(int argc, char* argv[]){
    printf("Checker process [%i]: Starting.\n", getpid());
    //return div(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    //case 0:  /* Child - reads from pipe */
    const int BSIZE = 100;
    char buf[BSIZE];
    ssize_t nbytes;
    nbytes = read(atoi(argv[1]), buf, 100);   /* Get data from pipe */
    /* At this point, a further read would see end of file ... */
    close(atoi(argv[1]));                       /* Finished with pipe */
    printf("Checker process [%i]: got %s\n", getpid(), buf);
    return 1;
//    exit(EXIT_SUCCESS);
} 

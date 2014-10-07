#include <stdio.h>

int div(int divisor, int dividend){
    if((dividend % divisor)==0){
        //was divisable (true)
        printf("Checker process [%i]: %i *IS* divisable by %i.\n", getpid(), dividend, divisor);
        printf("Checker process [%i]: Returning 1.\n", getpid());
        return 1;
    }else{
        printf("Checker process [%i]: %i *IS NOT* divisable by %i.\n", getpid(), dividend, divisor); 
        printf("Checker process [%i]: Returning 0.\n", getpid());
        return 0;
    }

}
int main(int argc, char* argv[]){
    printf("Checker process [%i]: Starting.\n", getpid());
    return div(atoi(argv[1]), atoi(argv[2]));
} 

#include "calc.h"
#include <math.h>

const int MAXNUMPRIMES=20;

int sumf_factorsum(int n, int primes[], int expo[], int numfactors);
int sumf_factor(int n, int primes[], int expo[]);
void sumf_removefact(int *n, int fact, int primes[], int expo[], int *numfactors);

int sumf()
{
	int	n;
	int	primes[MAXNUMPRIMES];
	int	expo[MAXNUMPRIMES];
	int	numfactors;
	double  dubn;


	dubn=pop();
	if (floor(dubn)<=0) {
		msg("The sum of factors is undefined for nonpositive integers");
		push((number)dubn);
		return FAILURE;
	}
	n=(int) floor(dubn);
	numfactors = sumf_factor(n, primes, expo);
	push((number)sumf_factorsum(n, primes, expo, numfactors));
	return SUCCESS;
}

int sumf_factorsum(int n, int primes[], int expo[], int numfactors)
{
	int prod, sum, power;
	int i, p;
	

	prod=1;
	for (i=1; i<=numfactors; i++) {
		sum=0;
		power=1;
		for (p=0; p<=expo[i]; p++) {
			sum += power;
			power *= primes[i];
		}
		prod *= sum;
	}
	return (prod-n);
}

int sumf_factor(int n, int primes[], int expo[])
{
	int	numfactors;
	int	fact;

	numfactors=0;
	if( n%2==0 ) sumf_removefact(&n, 2, primes, expo, &numfactors);
	if( n%3==0 ) sumf_removefact(&n, 3, primes, expo, &numfactors);
	if( n%5==0 ) sumf_removefact(&n, 5, primes, expo, &numfactors);

	fact=7;
	while( fact*fact <= n ) {
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=4;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=2;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=4;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=2;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=4;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=6;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=2;
		if( n%fact==0 )
			sumf_removefact(&n, fact, primes, expo, &numfactors);
		fact+=6;
	}
	if( n>1 )
		sumf_removefact(&n, n, primes, expo, &numfactors);
	return(numfactors);
}

void sumf_removefact(int *n, int fact, int primes[], int expo[], int *numfactors)
{
	primes[++*numfactors]=fact;
	expo[*numfactors]=0;
	while( *n%fact==0  ){
		*n/=fact;
		expo[*numfactors]++;
	}
}

static func_info fi(sumf, "sumf", "sum of factors");

/* Powerful digit counts

Problem 63
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.
How many n-digit positive integers exist which are also an nth power?

Pergjigje:  49  */

#include <math.h>
#include <stdio.h>

static inline int ispow(int i) {

	int x,nc;
	double check ;

	for (nc = 0,x = i ; x > 0 ; x /= 10,nc++)
	;

	le pogledt ce je all good */
	check = pow(i , (1.0 / (double) nc) );
	
	if ( (double)(check - (int)check) <= 0.00000001 || (double)(check - (int)check) >= 0.999999999)
		return 1 ;
		
	return 0;
}

int
main() {

	int j = 1,i;
	for (i = 1; i < 1000000000; i++) 
		if (ispow(i)) 
			j++;

	return printf("%d\n" , j);;
}
/*   Counting summations

Problem 76
It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?


Pergjigje:  190569291    */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

/*
 * P(n) = Sum((-1)**(k+1) * (P(n - k(3k - 1)/2) + P(n - k(3k + 1)/2)))
 * where k = 1 ... n
 */
intmax_t PartitionP (intmax_t n, intmax_t aiPn [])
{
    if (n < 0)
	return 0;
    
    if (aiPn [n] > 0)
	return aiPn [n];
    
    intmax_t Pn = 0;
    for (intmax_t k = 1; k <= sqrt (n); ++k)
    {
	intmax_t n1 = n - ((k * (3 * k - 1)) >> 1);
	intmax_t n2 = n - ((k * (3 * k + 1)) >> 1);
	
	intmax_t Pn1 = PartitionP (n1, aiPn);
	intmax_t Pn2 = PartitionP (n2, aiPn);
	
	if (k & 1)
	    Pn += Pn1 + Pn2;
	else
	    Pn -= Pn1 + Pn2;
    }
    aiPn [n] = Pn;
    return Pn;
}

int main ()
{
    intmax_t aiPn [101];
    memset (aiPn, 0, sizeof (aiPn));
    aiPn [0] = 1;
    
    printf ("Answer: %ld\n", PartitionP (100, aiPn) - 1);
    return 0;
}
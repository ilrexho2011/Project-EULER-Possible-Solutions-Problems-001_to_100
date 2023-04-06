/*  Digit factorial chains

Problem 74
The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; 
it turns out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a 
starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?


Pergjigje:  402  */

#include <stdio.h>

long fact(int);

long facdigit(int);

int IsIn(const int, long *, const int);

int main()
{
    int i, chains = 0, j = 0;
    long facdigitarray[70] = {0};
	for (i=2; i<=1000000; i++, j = 0)
	{
	    facdigitarray[j] = i;
	    do
	    {
	        facdigitarray[j+1] = facdigit(facdigitarray[j]);
        }while ( !(IsIn(facdigitarray[++j], facdigitarray, j-1)) && j<70);
        if (j == 60)
        {
            chains++;
        }
        j = 0;
    }
	printf("total number of chains = %d\n", chains);
	return 0;
}

long fact(int x)
{
    if  (x<=1)
        return 1;
    else
        return x*fact(x-1);
}

long facdigit(int x)
{
    long factsum = 0;
    while (x != 0)
    {
        factsum += fact(x%10);
        x /= 10;
    }
    return factsum;
}

int IsIn(const int var, long *searchin, const int lenght)
{
    int i;
    for (i=0; i<=lenght; i++)
    {
        if (searchin[i] == var)
            return 1;
    }
    return 0;
}
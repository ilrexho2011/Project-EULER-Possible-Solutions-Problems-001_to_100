/*   Amicable chains

Problem 95
The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.

Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.

Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:

12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)

Since this chain returns to its starting point, it is called an amicable chain.

Find the smallest member of the longest amicable chain with no element exceeding one million.

Pergjigje:  14316   */

#include <stdio.h>

#define NMAX 1000001

int divisorSum[NMAX];

int
getDivisorSum()
{
	int i, j;
	for(i=1; i<NMAX; i++)
		for(j=2*i; j<NMAX; j+=i)
			divisorSum[j] += i;
}

int
findCycle(int i, int *num)
{
	int p1 = i, p2 = i, clen = 0, count = 0;
	*num = NMAX;
	do {
		p1 = divisorSum[p1]; if(p1 >= NMAX || p1 < i) return -1;
		p2 = divisorSum[p2]; if(p2 >= NMAX || p2 < i) return -1;
		p2 = divisorSum[p2]; if(p2 >= NMAX || p2 < i) return -1;
		if(count == 1)	clen++,	*num = p1<*num?p1:*num;
		if(p1 == p2)	count++;
	}while(count != 2);
	return clen;
}

int
main()
{
	int i, len, maxlen = 0, maxnum, num;

	getDivisorSum();

	for(i=2; i<NMAX; i++) {
		len = findCycle(i, &num);
		if(len>maxlen)	maxlen = len,	maxnum = num;
	}
	printf("%d\n", maxnum);

	return 0;
}
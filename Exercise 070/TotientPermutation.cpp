/*  Totient permutation
 
Problem 70
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine 
the number of positive numbers less than or equal to n which are relatively prime to n. 
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

Pergjigje:  8319823  */

#include <iostream>
#include <iomanip>
using namespace std;

int cmp(const void* a, const void* b)
{
	const char* s1 = (const char*)a;
	const char* s2 = (const char*)b;

	return *s1 - *s2;
}

bool perm(int a, int b)
{
	static char b1[1024];
	static char b2[1024];

	sprintf(b1, "%d", a);
	sprintf(b2, "%d", b);

	int l1 = strlen(b1);
	int l2 = strlen(b2);

	if (l1 != l2)
		return false;

	qsort(b1, l1, 1, cmp);
	qsort(b2, l2, 1, cmp);

	return !strcmp(b1, b2);
}

unsigned int f(unsigned int n)
{
	assert(n >= 2);
	unsigned int* p = new unsigned int[n + 1];
	unsigned int i, j;
	for( i = 2 ; i <= n ; ++i ) p[i] = i - 1;
	long double t, mix_t = 50;
	unsigned int mix_i = 2;
	for( i = 2 ; i <= n ; ++i )
	{
		if( p[i] == i - 1 ) for( j = n / i ; j >= 2 ; --j ) p[i * j] -= p[j];

		t = static_cast<long double>(i) / p[i];
		if( t < mix_t && perm(i, p[i]))
		{
			mix_t = t;
			mix_i = i;
		}
	}
	delete[] p;
	p = NULL;
	return mix_i;
}
 
int main()
{     
	f(10000000 - 2);
	return 0;
}

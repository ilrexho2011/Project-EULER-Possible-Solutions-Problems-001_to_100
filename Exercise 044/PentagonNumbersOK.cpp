/*  Pentagon numbers
Pentagonal numbers are generated by the formula, Pn=n(3n-1)/2. 
The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 
70 - 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and 
difference are pentagonal and D = |Pk - Pj| is minimised; what is the value of D?

returns the answer 5482660 */

#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;


bool condition_met(int, int);
int difference(int, int);

int main() 
{
	clock_t start = clock();

	int j = 2;
	int k;
	int min = 0;

	while(min == 0)
	{
		for(k = j - 1; k > 0; k--)
			if(condition_met(j, k))
				min = difference(j, k);

		j++;
	}

	clock_t end = clock();

	cout << min << endl;
	cout << "Time elapsed: " << static_cast<float>(end - start) / 1000 << " seconds." << endl;
}

bool condition_met(int j, int k)
{
	// assumed: j > k
	// (if not the case, implement swap)

	double d1, d2;
	double x;
	
	d1 = 1 + 12 * ( (j * (3 * j - 1)) + (k * (3 * k - 1)) );
	d2 = 1 + 12 * ( (j * (3 * j - 1)) - (k * (3 * k - 1)) );
	
	
	// 1. condition:
	x = (1 + sqrt(d1)) / 6;
	if(floor(x) != x)
		return false;

	// 2. condition:
	x = (1 + sqrt(d2)) / 6;
	if(floor(x) != x)
		return false;
	
	return true;
}

int difference(int j, int k)
{
	return (( (j - k) * (3 * (j + k) - 1) ) / 2);
}

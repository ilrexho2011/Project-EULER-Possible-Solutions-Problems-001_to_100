/*   Coin partitions

Problem 78
Let p(n) represent the number of different ways in which n coins can be separated into piles. 
For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

OOOOO
OOOO   O
OOO   OO
OOO   O   O
OO   OO   O
OO   O   O   O
O   O   O   O   O
Find the least value of n for which p(n) is divisible by one million.


Pergjigje:  55374    */

#include <iostream>
#include <vector>
#include "gmpxx.h"

using std::cout; using std::vector;
typedef unsigned int uint;

int main()
{
	const uint N = 1000000;
	vector<mpz_class> p(2,1);
	
	
	for (uint n = 2; mpz_divisible_ui_p(p[p.size()-1].get_mpz_t(), N) == 0; n++) {
		mpz_class nextP = 0;
		int sign = 1;
		
		for (uint k = 1; k <= n; k++) {
			int arg = n - (k*(3*k-1))/2;
			if (arg < 0) 
				break;
			else
				nextP += sign*p[arg];
			arg = n - (k*(3*k+1))/2;
			if (arg < 0) 
				break;
			else
				nextP += sign*p[arg];
			
			sign *= -1;		
		}
		p.push_back(nextP);
	}
	
	cout << p.size()-1;
	return 0;
}
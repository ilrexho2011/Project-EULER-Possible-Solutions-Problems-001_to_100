/*   Prime power triples
 
Problem 87
The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 22 + 23 + 24
33 = 32 + 23 + 24
49 = 52 + 23 + 24
47 = 22 + 33 + 24

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?


Pergjigje:  1097343   */

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef unsigned long long uint;


void primeSieve (vector<uint>&, const uint&);

int main()
{
	const uint N = 50000000;
	const uint LIMITS [] = {static_cast<uint>(pow(N, 1./4)), 
			                static_cast<uint>(pow(N, 1./3)), 
			                static_cast<uint>(pow(N, 1./2))};
	vector<uint> primes;
	
	
	// construct a prime table
	primeSieve(primes, LIMITS[2]);
	
	set<uint> nums;
	for (uint i = 0; primes[i] <= LIMITS[0]; i++)
		for (uint j = 0; primes[j] <= LIMITS[1]; j++) 
			for (uint k = 0; primes[k] <= LIMITS[2]; k++) {
				uint result = static_cast<uint>(pow(primes[k], 2.)) + 
							  static_cast<uint>(pow(primes[j], 3.)) + 
							  static_cast<uint>(pow(primes[i], 4.));
				if (result < N)
					nums.insert(result);
				else break;
			}
	
	cout << nums.size();
	return 0;
}

void primeSieve (vector<uint>& primes, const uint& limit)
{
	vector<bool> sieve(limit+1, true);
	
	sieve[0] = sieve[1] = false;
	
	for (uint i = 2; i*i < sieve.size(); i++)
		if (sieve[i])
			for (uint j = i*i; j < sieve.size(); j += i)
				sieve[j] = false;
	
	primes.reserve(count(sieve.begin(), sieve.end(), true));
	
	for (vector<uint>::size_type i = 0; i < sieve.size(); i++)
		if (sieve[i])
			primes.push_back(i);
}
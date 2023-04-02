/* Prime pair sets
 
Problem 60
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

Pergjigja:  26033   */

#include <iostream>
using std::cout;
using std::endl;

typedef unsigned long long int uint;

const uint SIEVE_MAX = 10000;
const uint PRIMES_MAX = SIEVE_MAX*SIEVE_MAX;
bool siivilae[PRIMES_MAX]; // sieve of eratosthenes

//d = digits ja vÃƒÆ’Ã‚Â¤hÃƒÆ’Ã‚Â¤ pÃƒÆ’Ã‚Â¤ÃƒÆ’Ã‚Â¤lle
uint d(uint a)
{
	uint n=1;
	while(a>0)
	{
		n*=10;
		a/=10;
	}
	return n;
}

#define testi(i,j) r=k(i,j); \
			if (r>PRIMES_MAX) \
				break;\
			if (!siivilae[r])\
				continue;




//lyhenne sanalle "konsatenatenatoi"
uint k(uint a, uint b)
{
	return a*d(b)+b;
}

void siiviloi()
{
	memset(siivilae, true, PRIMES_MAX*sizeof(bool));
	siivilae[0] = false;
	siivilae[1] = false;
	for(uint i=2; i<SIEVE_MAX; i++)
	{
		if (siivilae[i] == false)
			continue;
		for(uint j=i*i; j<PRIMES_MAX; j+=i)
			siivilae[j] = false;
	}
}



int main()
{
	siiviloi();
	uint r, s=100000;
	for(uint i=0; i<100; i++)
		cout << i << ": " << siivilae[i] << endl;
	for(uint a=3; a<PRIMES_MAX; a+=2)
	{
		if (a > s)
			break;
		if (!siivilae[a])
			continue;
		for(uint b=a+2; b<PRIMES_MAX; b+=2)
		{
			if (a+b > s)
				break;
			if (!siivilae[b])
				continue;
			testi(a,b);
			testi(b,a);
			for(uint c=b+2; c<PRIMES_MAX; c+=2)
			{
				if (a+b+c > s)
					break;
				if (!siivilae[c])
					continue;
				testi(a,c);
				testi(c,a);
				testi(b,c);
				testi(c,b);
				for(uint d=c+2; d<PRIMES_MAX; d+=2)
				{
					if (a+b+c+d > s)
						break;
					if (!siivilae[d])
						continue;
					testi(a,d);
					testi(d,a);
					testi(b,d);
					testi(d,b);
					testi(c,d);
					testi(d,c);
					for(uint e=d+2; e<PRIMES_MAX; e+=2)
					{
						if (a+b+c+d+e > s)
							break;
						if (!siivilae[e])
							continue;
						testi(a,e);
						testi(e,a);
						testi(b,e);
						testi(e,b);
						testi(c,e);
						testi(e,c);
						testi(d,e);
						testi(e,d);
						if (a+b+c+d+e < s)
							s=a+b+c+d+e;
						cout << a << ", " << b << ", " << c << ", " << d << ", " << e << endl;
						cout << s << endl;
					}
				}
			}
		}

	}
return 0;
}
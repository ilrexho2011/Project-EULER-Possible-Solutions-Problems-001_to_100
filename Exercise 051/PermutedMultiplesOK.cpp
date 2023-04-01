//	Permuted multiples
/*	It can be seen that the number, 125874, and its double, 251748, 
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, 
such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
Pergjigja e sakte eshte :  142857	*/

#include<iostream>
using namespace std;
typedef unsigned int uint;

inline bool f(const uint nr)
{
	char stn[10];
	uint i =0;
	while(i < 10)
		stn[i++] = 0;
	uint tmp = nr;
	i=0;
	while (tmp)
	{
		stn[i++] = tmp % 10 + '0';
		tmp/=10;
	}
	uint multy = 2;
	while(multy < 7)
	{
		tmp = nr*multy++;
		while(tmp)
		{
			bool found = false;
			i=0;
			while (stn[i])
				if(stn[i++]-'0' == tmp%10)
				{
					found = true;
					break;
				}
			if(!found) return false;
			tmp/=10;
		}
	}
	return true;
}

int main() 
{
	uint nr =2;
	while (!f(nr++))
	{}
	cout << nr << endl;
}

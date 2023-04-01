/*  Zevendesimet shifrore ne numrat Prim
By replacing the 1st digit of the 2-digit number *3, it turns out that six 
of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, 
this 5-digit number is the first example having seven primes among 
the ten generated numbers, yielding the family: 
56003, 56113, 56333, 56443, 56663, 56773, and 56993. 
Consequently 56003, being the first member of this family, 
is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number 
(not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
Pergjigja e sakte 121313 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int P = 1000000;
vector<bool> isPrime(P, true);

void seive() {
	for(int i=2; i<P; i++)
	{
		if(isPrime[i])
		{
			for(int j=2; i*j<P; j++)
				isPrime[i*j] = false;
		}
	}
}

int giveNextNum(vector<int> &ar, int d, int x, int y, int z) {
	int num = 0;
	for(int i=0; i<6; i++) {
		if(i == x || i == y || i == z)
			num = num*10 + d;
		else
			num = num*10 + ar[i];
	}
	return num;
}

void giveNumVector(int num, vector<int> &ar) {
	for(int i=0; i<6; i++) {
		ar[5-i] = num%10;
		num /= 10;
	}
}

void primeFamily(int num, int &len) {
	vector<int> ar(6);
	int orig = num;
	int local_len = 1;
	giveNumVector(num, ar);
	int i=0;
	while(ar[i] == 0)
		i++;
	for(; i<6; i++) {
		for(int j=i+1; j<6; j++) {
			for(int z=j+1; z<6; z++) {
				local_len = 1;
				if(ar[i] == ar[j] && ar[i] == ar[z]) {
					for(int k=ar[i]+1; k<10; k++) {
						num = giveNextNum(ar, k, i, j, z);
						if(isPrime[num]){
							local_len++;
						}
					}
				}
				len = max(len, local_len);
			}
		}
	}
}

int main()
{
	seive();
	int len;
	for(int i=2; i<P; i++)
	{
		if(isPrime[i])
		{
			len = 1;
			primeFamily(i, len);
			if(len == 8)
			{
				cout << "Numri me i vogel me 8 prime : " << i << endl;
				return 0;
			}
		}
	}
	return 0;
}

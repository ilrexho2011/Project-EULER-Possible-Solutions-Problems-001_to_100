/* In England the currency is made up of pound, £, and pence, p, 
and there are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins? 
coins=[2,5,10,20,50,100,200]

def p(n=200,coin=200):
	if coin==2: return(n/2+1)
	m=n/coin
	c=0
	newcoin=coins[coins.index(coin)-1]
	while m>=0:
		c+=p(n-m*coin,newcoin)
		m-=1
	return c

print p()
This code returns the answer 73682 in 0.00183 seconds.
I did some research into this, and if we only have coins of 2p and 1p 
in our possession, the number of possible combinations is n/2+1, assuming 
integer division. n/2 combinations for the number of 2p coins and one option 
for no 2p coins. If we add a 5p coin, there are n/5 combinations for the number 
5p coins, as well as one option without 5p coins, so we loop over those combinations 
and check for each of them how many combinations there are possible. m can also be 0, 
so we've got that covered as well. The rest is done recursively.*/

#include <iostream>

using namespace std;

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int ways(int target, int avc)
{
    if (avc < 1) return 1;
    int res = 0;
    while (target >= 0)
    {
        res += ways(target, avc - 1);
        target -= coins[avc];
    }
     return res;
}

int main()
{
    cout << ways(200, 7) << endl;
}

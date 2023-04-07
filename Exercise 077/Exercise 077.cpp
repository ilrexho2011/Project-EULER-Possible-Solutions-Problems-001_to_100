/*   Prime summations

Problem 77
It is possible to write ten as the sum of primes in exactly five different ways:

7 + 3
5 + 5
5 + 3 + 2
3 + 3 + 2 + 2
2 + 2 + 2 + 2 + 2

What is the first value which can be written as the sum of primes in over five thousand different ways?

Pergjigje:  71    */

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 1000
long long nway[MAX + 1];
vector&lt;int&gt; coin;
bool prime(int n){
     for(int i = 0;coin[i]*coin[i] &lt;= n;++i)
        if(n%coin[i] == 0) return false;
     return true;
}
int main()
{
    coin.push_back(2);
    int k = 3;
    while(k &lt; 1000000){
         if(prime(k)) coin.push_back(k);
         k += 2;        
    }
    int i,j,n,v,c;

    v = coin.size();
    nway[0] = 1;
    for (i=0; i&lt;v; i++) {
       c = coin[i];
       for (j=c; j&lt;= MAX; j++)
           nway[j] += nway[j-c];
    }
    n = 10;
    while(nway[n] &lt; 5000) 
        ++n;
        
    printf("n = %d\n",n);
    getchar();
    return 0;
}

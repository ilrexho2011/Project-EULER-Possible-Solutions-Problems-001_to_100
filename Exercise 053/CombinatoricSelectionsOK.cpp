//	Combinatoric selections
/*	There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,

nCr =	
n!
r!(n-r)!
,where r = n, n! = n×(n-1)×...×3×2×1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 = n = 100, are greater than one-million?
Pergjigja e sakte eshte : 4075	*/

#include<stdio.h>
#include<math.h>

long long dp[101][101];

long long nCr(long long n,long long r) // using dynamic programming to calculate nCr;
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]!=-1){
        return dp[n][r];
    }
    else{
        dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
        return dp[n][r];
    }
}

int main()
{
    long long i,j,x,cnt=0,y;
    for(i=1;i<101;i++){
        for(j=1;j<i;j++){
            dp[i][j]=-1;
        }
    }
    for(i=1;i<101;i++){
        for(j=1;j<i;j++){
            x=nCr(i,j);
            if(x>1000000){
                y=i-(2*j)+1;
                cnt+=y;
                break;
            }
        }
    }
    printf("%lld\n",cnt);

}

/*   Cuboid route

Problem 86
A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.


However, there are up to three "shortest" path candidates for any given cuboid and the shortest route doesn't always have integer length.

It can be shown that there are exactly 2060 distinct cuboids, ignoring rotations, with integer dimensions, up to a maximum size of M by M by M, for which the shortest route has integer length when M = 100. This is the least value of M for which the number of solutions first exceeds two thousand; the number of solutions when M = 99 is 1975.

Find the least value of M such that the number of solutions first exceeds one million.

Pergjigje:  1818   */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <time.h>

struct timer
{
   clock_t t;
   timer() { t = clock(); }
   ~timer() { printf("runtime %.3f secs\n", getTime()); }
   double getTime() { return ((double)clock()-(double)t)/(double)CLOCKS_PER_SEC; }
};
int count(int m)
{
   int sum=0;
   int ix=1;
   while (++ix<(m<<1))
   {
      int n=m*m+ix*ix;
      int s=sqrt(n);
      int mx1=ix-m;
      int ixm1=ix-m-1;
      if (s*s==n)
         sum+=(ix>>1)-(ixm1>0?ixm1:0);
   }
   return sum;
}

int main(int argc, char**argv)
{
   timer t;
   const int N=1000000;
   int sum=0;
   int m=0;
   while (sum<=N)
      sum+=count(m++);
   printf("%d -- sum=%d\n",m-1,sum);
   return 0;
}
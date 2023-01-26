/*----------------------------------------------------------
	Shuma e numrave Prim poshte 10 eshte 2 + 3 + 5 + 7 = 17.
	Gjeni shumen e numrave Prim poshte vleres 2 milion.
	Pergjigja e sakte eshte 142913828922
	--------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isprime(unsigned long n);

int main(void)
{
    unsigned long num = 1000000;
    unsigned long x;
    unsigned long long y = 0;

    for(x = 2 ; x < num ; x++)
    {
        if(isprime(x))
        {
            y += x;
        }
    }
    printf("Answer = %llu\n", y);
    return 0;
}

bool isprime(unsigned long n)
{
    unsigned long i;
    unsigned long k;

    if(n <= 3)
    {
        if(n == 1)
        {
            return false;
        }
        return true;
    }
    if((n % 2) == 0)
    {
        return false;
    }
   k = sqrt(n) + 1;
   for (i = 3 ; i <= k ; i += 2)
   {
        if(n % i == 0)
        {
            return false;
        }
   }
   return true;
}

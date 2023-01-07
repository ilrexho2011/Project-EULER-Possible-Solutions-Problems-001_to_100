//  Faktori me i madh Prim i nje numri
//  Cdo numer natyror mund te perftohet si produkt i faktoreve
//  te cilet jane te gjithe numra Prim
//  Faktoret Prim te numrit 13195 jane 5, 7, 13 dhe 29.
//  Cili eshte faktori me i madh prim per numrin 600851475143 ?
//  Pergjigja e sakte eshte 6857

#include <stdio.h>
#include <stdbool.h>

bool isprime(unsigned long long v);

int main(void)
{
    unsigned long long num = 600851475143;
    unsigned long long max = 0;
    unsigned long long x;
    
    for(x = 2 ; (x * x) <= num ; x++)
    {
        if((num % x) == 0)
        {
            if(isprime(x))
            {
                if(x > max)
                {
                    max = x;
                }
            }
        }
    }
    printf("Pergjigje = %llu\n", max);
    return 0;
}

bool isprime(unsigned long long v)
{
    unsigned long long i = 0;
    bool rv = true;
    
    if(v != 1)
    {
        for(i = 2 ; i <= (v / 2) ; i++)
        {
            if(v % i == 0)
            {
                rv = false;
            } 
        }
    }
    else
    {
        rv = false;
    }
    return rv;
}

/* Champernowne's constant
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

returns the answer 210  */

#include <iostream>

int len(int n)
{
    int l=1;
    int t=n;
    while(n/=10)l++;
    return l;
}

int main()
{
    int prod = 1, i=1, pos=1, l=1;

    while(pos+l <= 100) 
    {
        pos+=l;
        l=len(++i);
    }
    int n = i;
    for(int p=0; p<l-100+pos-1;++p) n/=10;
    prod *= n%10;
    
    while(pos+l <= 1000) 
    {
        pos+=l;
        l=len(++i);
    }
    n = i;
    for(int p=0; p<l-1000+pos-1;++p) n/=10;
    prod *= n%10;
    
    while(pos+l <= 10000) 
    {
        pos+=l;
        l=len(++i);
    }
    n = i;
    for(int p=0; p<l-10000+pos-1;++p) n/=10;
    prod *= n%10;
    
    while(pos+l <= 100000) 
    {
        pos+=l;
        l=len(++i);
    }
    n = i;
    for(int p=0; p<l-100000+pos-1;++p) n/=10;
    prod *= n%10;
    
    while(pos+l <= 1000000) 
    {
        pos+=l;
        l=len(++i);
    }
    n = i;
    for(int p=0; p<l-1000000+pos-1;++p) n/=10;
    prod *= n%10;    
    
    std::cout << prod ;
}

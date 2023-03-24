#include <iostream>
using namespace std;
int SUM;
void sumOfPowers(int x,int powers[])
{
    int sum=0,number=x;
    int digit;
    while(x!=0)
    {
        digit=x%10;
        x/=10;
        sum+=powers[digit];
    }
    SUM+=number;
}
int main()
{
    int powers[10];
    powers[0]=0;
    for(int i=0;i<10;i++)
    {
        powers[i]=i*i*i*i*i;
    }
    for(int i=2;i<10000000;i++)
    {
        sumOfPowers(i,powers);
    }
    cout<<SUM<<'\n';
    return 0;
}

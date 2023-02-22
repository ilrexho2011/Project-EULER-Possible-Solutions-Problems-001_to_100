#include <iostream>
using namespace std;

int divisorCount(const unsigned long long x)
{
    int divizers = 0;
    unsigned long long i = 1;
    while(i <= x/i)
    {
        if(x % i == 0)
        {
            divizers++;
        }
        i++;
    }
    return divizers;
}

int main()
{
    bool test;
    unsigned long long total = 0, spread = 1;
    int divisors = 1;

    while(divisors < 500)
    {
        total+=spread;
        divisors = divisorCount(total);
        spread++;
        if(divisors > 500)
            cout << total << " " << spread << " " << divisors << endl;
    }


    cout << total << " is divisible by 500+ numbers" << endl;
    system("pause");
    return 0;
}

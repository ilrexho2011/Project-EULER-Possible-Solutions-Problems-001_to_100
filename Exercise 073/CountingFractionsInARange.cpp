/*  Counting fractions in a range

Problem 73
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

Pergjigje:  7295372   */

#include <set>
#include <iostream>

using namespace std;

class number
{
public:
    number(int x, int y) : _x(x), _y(y) {}
    bool operator<(const number &other) const
    {
        return ((_x*other._y) < (_y * other._x));
    }
private:
    int _x;
    int _y;
};

set<number> numbs;

int main()
{
    int i,j;
    number half(1,2);
    number third(1,3);
    for (i=0; i<=10000; ++i)
    {
        if(i%1000 == 0) cout << "i : " << i << endl;
        for (j=i+1; j<=10000; ++j)
        {
            number numb(i,j);
            if (third < numb && numb < half)
            {
                numbs.insert(numb);
            }
        }
    }
    cout << "Result : " << numbs.size() << endl;
    return 0;
}
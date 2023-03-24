/* The fraction 49/98 is a curious fraction, as an inexperienced 
mathematician in attempting to simplify it may incorrectly believe 
that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, 
less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator.
This returns the answer 100 in 0.008861 seconds. */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int fn = 0;
    int sn = 0;
    int fd = 0;
    int sd = 0;
    vector<int> list;

    for (int num = 12; num < 99; num++)
    {
        fn = num / 10;
        sn = num % 10;
        if (num % 10 == 0) continue;

        else if (fn == sn) continue;
        else
        {
            for (int den = 12; den < 99; den++)
            {
                fd = den / 10;
                sd = den % 10;
                if (den % 10 == 0) continue;

                else if (fd == sd) continue;
                else if (num == den || num / den > 1) continue;
                else
                {
                    if (fn == fd && (double) num / (double) den == (double) sn / (double) sd)
                    {
                        list.push_back(num);
                        list.push_back(den);
                    }
                    else if (fn == sd && (double) num / (double) den == (double) sn / (double) fd)
                    {

                        list.push_back(num);
                        list.push_back(den);
                    }
                    else if (sn == fd && (double) num / (double) den == (double) fn / (double) sd)
                    {
                        list.push_back(num);
                        list.push_back(den);
                    }
                    else if (sn == sd && (double) num / (double) den == (double) fn / (double) fd)
                    {
                        list.push_back(num);
                        list.push_back(den);
                    }
                    else continue;
                }
            }
        }
    }
    long NUM = 1;
    long DEN = 1;
    long temp = 0;
    long x = 1; // Value of 1 for the while loop downstream.
    long y = 0;

    for (int i = 0; i <= 6; i += 2)
    {
        NUM *= list.at(i);
        DEN *= list.at(i + 1);
    }

    if (NUM < DEN)
    {
        x = NUM;
        y = DEN;
    }
    else
    {
        x = DEN;
        y = NUM;
    }

    while (x > 0)
    {
        temp = y % x;
        y = x;
        x = temp;
    }
    cout << DEN / y << endl;
}

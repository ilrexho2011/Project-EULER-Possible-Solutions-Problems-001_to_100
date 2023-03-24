#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

unsigned int sumFactorialOfDigits (unsigned int);
int factorial (int);

int main() 
{
    clock_t start = clock();
    int total = 0;

    for (unsigned int i = 10; i < 1000000; i++)
        if (i == sumFactorialOfDigits (i))
            total += i;

    cout << total << endl 
         << "Process took " << (static_cast<double> (clock()) - start) / CLOCKS_PER_SEC << " seconds." << endl;
    system("pause");
    return 0;
}

unsigned int sumFactorialOfDigits (unsigned int num)
{
    unsigned int total = 0;
    char buffer[16];
    string str;

    sprintf (buffer, "%i", num);
    str = buffer;

    for (unsigned int i = 0; i < str.size (); i++)
        total += factorial (str[i] - '0');

    return total;
}

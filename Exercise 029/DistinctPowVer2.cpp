#include <iostream>
#include <ctime>
#include <cmath>
#include <set>

using namespace std;

int main() 
{
    clock_t start = clock();
    int total = 0;

    set<double> answer;
    for (double a = 2; a <= 100; a++)
        for (double b = 2; b <= 100; b++)
            answer.insert (pow (a, b));
    total = answer.size ();  

    cout << total << endl 
         << "Process took " << (static_cast<double> (clock()) - start) / CLOCKS_PER_SEC << " seconds." << endl;
    system("pause");
    return 0;
}

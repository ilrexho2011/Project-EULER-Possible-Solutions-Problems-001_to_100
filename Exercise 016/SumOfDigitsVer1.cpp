#include<iostream>
#include<iomanip>
using namespace std;

unsigned long sumDigits(unsigned long long number) {

    unsigned long sum = 0;

    while (number) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    unsigned long long n = 1;
    int power = 0;
    while(n) {
        cout << setw(3) << power << setw(20) << n << setw(4) << sumDigits(n) << endl;
        power++;
        n <<= 1;
    }
    return 0;
}


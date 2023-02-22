#include <iostream>

using namespace std;
inline void triangle(int &num, int &interval)
{
    num = ((interval * interval) + interval ) / 2;
}

int main()
{
    long int input;
    int num = 1, interval = 1, divisor = 1, no_divisor = 0;

    std::cout << "Enter factor limit for Triangle number: ";
    std::cin >> input;

  

    for (;;)
    {
        while (divisor <= num)
        {
            if (0 == num % divisor) //check factor;
            {
                std::cout << "factor: " << divisor << "\n";
                no_divisor++;
                if (no_divisor > input) //divisor count over input number, jump to exit;
                {
                    goto exit;
                }
            }
            divisor++;
        }
        std::cout << "\n";
        interval++;
        triangle(num, interval);
        divisor = 1; //reset divisor back to 1;
        no_divisor = 0; //reset divisor count back to 0;
    }
    exit: std::cout << "the first Triangle number to have over " << input << " divisors : " << num << "\n";

    
    return 0;
}

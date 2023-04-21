/*   Square digit chains

Problem 92
A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?

Pergjigje:  8581146   */

/* Project Euler Problem 92 */
#include <iostream>
using namespace std;

long runFormula(long number)
{
	int digit;
	long next = 0;
	
	while(1)
	{
		while(number > 0)
		{
			digit = number % 10;
			next += digit * digit;
			number /= 10;
		}
		
		if(next == 1)
			return next;

		if(next == 89)
			return next;
		
		number = next;
		next = 0;
	}
}

int main()
{	
	long start = 2, count = 0;

	for(long i=2; i<10000000; ++i)
	{
		if(runFormula(i) == 89)
			++count;
	}
	
	cout << "Count: " << count << endl;

	return 0;
}
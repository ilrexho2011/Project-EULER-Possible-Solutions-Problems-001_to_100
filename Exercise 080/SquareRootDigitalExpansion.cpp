/*   Square root digital expansion

Problem 80
It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.

The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.

Pergjigje:  40886   */


#include <iostream>
#include <gmpxx.h>
#include <gmp.h>

int main ()
{
    mpz_class num;
    
    mpz_t c_shifter, c_limiter;
    
    mpz_init (c_shifter);
    mpz_init (c_limiter);
    
    mpz_pow_ui (c_limiter, mpz_class (10).get_mpz_t (), 100);
    mpz_pow_ui (c_shifter, c_limiter, 2);
    
    const mpz_class shifter (c_shifter), limiter (c_limiter);

    mpz_clear (c_shifter);
    mpz_clear (c_limiter);

    int sum = 0;
    
    for (num = 1; num <= 100; ++ num)
    {
	if (mpz_perfect_square_p (num.get_mpz_t ()))
	    continue;

	mpz_class sq = sqrt (num * shifter);

	while (sq >= limiter)
	    sq /= 10;
	
	while (sq != 0)
	{
	    sum += static_cast<mpz_class>(sq % 10).get_si ();
	    sq /= 10;
	}
    }
        
    std::cout << "Answer: " << sum << std::endl;
    return 0;
}
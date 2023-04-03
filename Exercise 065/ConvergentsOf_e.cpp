/* Convergents of e
 
   Problem 65
   The square root of 2 can be written as an infinite continued fraction.
   The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
   Pergjigja:  272     */

#include <iostream>
#include <gmpxx.h>

#define NTHTERM(n) ((n % 3 == 2) ? (n + 1) * 2 / 3 : (n == 0 ? 2 : 1))

// Finds the numerator and denominator of the nth continued fraction.
void nth_fraction (mpz_class &num, mpz_class &den, const int iter, const int target)
{
    if (iter == target)
    {
        // Innermost term is just the nth term.
        num = NTHTERM (iter);
        den = 1;
        return;
    }

    nth_fraction (num, den, iter + 1, target);

    /*
     * nthterm +      1
     *           ----------
     *           n+1st term
     *
     * = nthterm + n+1st denominator
     *             -----------------
     *              n+1st numerator
     *
     * = nthterm * (n+1st numerator) + (n+1st denominator)
     *   -------------------------------------------------
     *                    n+1st numerator
     */


    // Swap numerator and denominator of n+1st term
    num ^= den;
    den ^= num;
    num ^= den;

    // Add nth term.
    num += den * NTHTERM (iter);
}

int sum_digits (mpz_class num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += static_cast<mpz_class>(num % 10).get_si ();
        num /= 10;
    }
    return sum;
}

int main ()
{
    mpz_class num, den;

    // Zero-based numbering, so 100th term is #99.
    nth_fraction (num, den, 0, 99);

    std::cout << "Answer: " << sum_digits (num) << std::endl;
    return 0;
}
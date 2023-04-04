/*  Magic 5-gon ring

Problem 68 Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.

Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), 
each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.

It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.

Total Solution Set 9 4,2,3; 5,3,1; 6,1,2 9 4,3,2; 6,2,1; 5,1,3 10 2,3,5; 4,5,1; 6,1,3 10 2,5,3; 6,3,1; 4,1,5 11 1,4,6; 3,6,2; 5,2,4 11 1,6,4; 5,4,2; 3,2,6 12 1,5,6; 2,6,4; 3,4,5 12 1,6,5; 3,5,4; 2,4,6 By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.

Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. 
What is the maximum 16-digit string for a "magic" 5-gon ring?

Pergjigje: 6531031914842725  */

#define __STDC_LIMIT_MACROS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <tr1/cstdint>

uintmax_t max_string (std::deque<char> &permut)
{
    uintmax_t max = 0L;
    do
    {
	std::deque<bool> sat (10, false);
	
	for (std::deque<char>::iterator i = permut.begin (); i != permut.end ();
	     ++i)
	    sat [*i - 1] = true;
	
	int t = permut [1] + permut [0] + permut [5]; // target
	
#if 0
	std::cout << (int) permut [5] << ' ' << (int) permut [0] << ' ' << (int) permut [1] << '=' << t << "; " <<
	    t - permut [2] - permut [1] << ' ' << (int) permut [2] << ' ' << (int) permut [1] << "; " <<
	    t - permut [3] - permut [2] << ' ' << (int) permut [3] << ' ' << (int) permut [2] << "; " <<
	    t - permut [4] - permut [3] << ' ' << (int) permut [4] << ' ' << (int) permut [3] << "; " <<
	    t - permut [0] - permut [4] << ' ' << (int) permut [0] << ' ' << (int) permut [4] << '.' << std::endl;
#endif
	
	int a6 = t - permut [1] - permut [2];
	
	if (a6 >= 1 && a6 <= 10 && !sat [a6 - 1]) // a1 + a2 + a6 = t
	{
	    sat [a6 - 1] = true;
	
	    int a7 = t - permut [2] - permut [3];
	
	    if (a7 >= 1 && a7 <= 10 && !sat [a7 - 1]) // a2 + a3 + a7 = t
	    {
		sat [a7 - 1] = true;
	
		int a8 = t - permut [3] - permut [4];
	
		if (a8 >= 1 && a8 <= 10 && !sat [a8 - 1]) // a3 + a4 + a8 = t
		{
		    sat [a8 - 1] = true;
	
		    int a9 = t - permut [4] - permut [0];
	
		    if (a9 >= 1 && a9 <= 10 && !sat [a9 - 1]) // a4 + a0 + a9 = t
		    {
			sat [a9 - 1] = true;

			// This permutation qualifies. Arrange groups.
			uintmax_t qual = 0;
			char posns [] =
			{
			    permut [5], permut [0], permut [1],
			    a6,         permut [1], permut [2],
			    a7,         permut [2], permut [3],
			    a8,         permut [3], permut [4],
			    a9,         permut [4], permut [0]
			};
			
			// Rotate to have the smallest external number first.
			while (posns [0] > posns [3] || posns [0] > posns [6] ||
			       posns [0] > posns [9] || posns [0] > posns [12])
			{
			    for (size_t i = 0; i < sizeof (posns) / sizeof (posns [0]) - 3; ++i)
			    {
				posns [i] ^= posns [i + 3];
				posns [i + 3] ^= posns [i];
				posns [i] ^= posns [i + 3];
			    }
			}
	
			// Construct string.
			for (size_t i = 0; i < sizeof (posns) / sizeof (posns [0]); ++i)
			{
			    if (posns [i] == 10)
				qual *= 100L;
			    else
				qual *= 10L;
	    
			    qual += posns [i];
			}
			if (qual > max) max = qual;
		    }
		}
	    }
	}
    } while (std::next_permutation (permut.begin (), permut.end ()));
    
    return max;
}

uintmax_t choose_inners (void)
{
    std::deque<char> choices (6);
    uintmax_t max = 0;

    // Choose six numbers to permute to find solutions.
    for (int i = 1; i <= 4; ++i)
    {
	choices [0] = i;
	for (int j = i + 1; j <= 5; ++j)
	{
	    choices [1] = j;
	    for (int k = j + 1; k <= 6; ++k)
	    {
		choices [2] = k;
		for (int l = k + 1; l <= 7; ++l)
		{
		    choices [3] = l;
		    for (int m = l + 1; m <= 8; ++m)
		    {
			choices [4] = m;
			for (int n = m + 1; n <= 9; ++n)
			{
			    choices [5] = n;
			    uintmax_t ch_max = max_string (choices);
			    
			    if (ch_max > max) max = ch_max;
			}
		    }
		}
	    }
	}
    }
    return max;
}

int main ()
{
    std::cout << "Answer: " << choose_inners () << std::endl;
    return 0;
}
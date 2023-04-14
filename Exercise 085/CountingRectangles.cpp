/*   Counting rectangles

Problem 85
By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:

Although there exists no rectangular grid that contains exactly two million rectangles, 
find the area of the grid with the nearest solution.

Pergjigje:  2772   */

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main ()
{
    int min_diff = INT_MAX; int area = 0;
    const int limit = ceil (sqrt (2000000));
    for (int m = 1; m <= limit; ++m)
    {
	int n = (int) (sqrt (32000000 / m / (m + 1)) - 1) >> 1;
	int r = m * (m + 1) * n * (n + 1);
	r -= 8000000;
	if (r < 0) r = -r;
	if (r < min_diff)
	{
	    min_diff = r;
	    area = m * n;
	}
	
	r = m * (m + 1) * (n + 1) * (n + 2);
	r -= 8000000;
	if (r < 0) r = -r;
	if (r < min_diff)
	{
	    min_diff = r;
	    area = m * (n + 1);
	}	
    }
    printf ("Answer: %d\n", area);
    return 0;
}
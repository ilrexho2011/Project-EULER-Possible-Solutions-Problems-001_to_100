/*   Cube digit pairs
 
Problem 90
Each of the six faces on a cube has a different digit (0 to 9) written on it; the same is done to a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.

For example, the square number 64 could be formed:


In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.

For example, one way this can be achieved is by placing {0, 5, 6, 7, 8, 9} on one cube and {1, 2, 3, 4, 8, 9} on the other cube.

However, for this problem we shall allow the 6 or 9 to be turned upside-down so that an arrangement like {0, 5, 6, 7, 8, 9} and {1, 2, 3, 4, 6, 7} allows for all nine square numbers to be displayed; otherwise it would be impossible to obtain 09.

In determining a distinct arrangement we are interested in the digits on each cube, not the order.

{1, 2, 3, 4, 5, 6} is equivalent to {3, 6, 4, 1, 2, 5}
{1, 2, 3, 4, 5, 6} is distinct from {1, 2, 3, 4, 5, 9}

But because we are allowing 6 and 9 to be reversed, the two distinct sets in the last example both represent the extended set {1, 2, 3, 4, 5, 6, 9} for the purpose of forming 2-digit numbers.

How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?

Pergjigje:  1217   */

#include <iostream>
#include <vector>

using std::vector;
void genDigitCombs (vector<vector<bool> >&);

int main()
{
	unsigned validArrangements(0);
	vector<vector<bool> > digitCombs;
	const char* SQUARES[] = {"01", "04", "09", "16", "25", "36", "49", "64", "81"};

	// build a vector of combination LUT's
	genDigitCombs(digitCombs);

	for (size_t i = 0; i < digitCombs.size()-1; ++i)
		for (size_t j = i+1; j < digitCombs.size(); ++j) {
			bool includesAllSquares(true);
			for (size_t k = 0; k < sizeof(SQUARES)/sizeof(SQUARES[0]); ++k) {
				if(!(digitCombs[i][SQUARES[k][0]-'0'] && 
				     digitCombs[j][SQUARES[k][1]-'0'] ||
				     digitCombs[i][SQUARES[k][1]-'0'] && 
				     digitCombs[j][SQUARES[k][0]-'0'])) 
				{
					includesAllSquares = false;
					break;
				}
			}
			if (includesAllSquares)
				validArrangements++;
		}
	std::cout << validArrangements;
return 0;
}

void genDigitCombs (vector<vector<bool> >& digitCombs)
{
	const unsigned n(10);
	const unsigned k(6);
	vector<size_t> ind(k);

	// initialize the indices vector
	for (size_t i = 0; i < ind.size()-1; ++i)
		ind[i] = i;
	ind[k-1] = k-2;

	do {
		size_t i, j;

		for (i = k-1; n - k + i == ind[i] && i >= 0; --i)
			;
		ind[i]++;
		for (j = i; j < ind.size()-1; ++j)
			ind[j+1] = ind[j] + 1;

		vector<bool> digits(n,false);

		for (i = 0; i < ind.size(); ++i)
			digits[ind[i]] = true;

		// the 6 or 9 are allowed to be turned upside-down.
		if (!digits[6] && digits[9])
			digits[6] = true;
		else if (digits[6] && !digits[9])
			digits[9] = true;

		digitCombs.push_back(digits);
	} while (ind.front() != n-k);
}

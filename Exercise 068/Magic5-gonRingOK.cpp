//	Magic 5-gon ring
/*	Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.


Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), 
each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.

It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.

Total	Solution Set
9	4,2,3; 5,3,1; 6,1,2
9	4,3,2; 6,2,1; 5,1,3
10	2,3,5; 4,5,1; 6,1,3
10	2,5,3; 6,3,1; 4,1,5
11	1,4,6; 3,6,2; 5,2,4
11	1,6,4; 5,4,2; 3,2,6
12	1,5,6; 2,6,4; 3,4,5
12	1,6,5; 3,5,4; 2,4,6
By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.

Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. 
What is the maximum 16-digit string for a "magic" 5-gon ring?
I used a pointer array, and aligned it to the values of another array containing numbers 1-10 
to simulate the '5-gon'. I reused an algorithm for ordered permutations from a previous problem 
(modified for descending order) to rotate the numbers. First permutation found would be the answer. 
Sort of an optimal brute force.

Pergjigja e sakte eshte: 6531031914842725	*/

#include <iostream>
#define swap(a, b) do { tmp = a; a = b; b = tmp; } while(0)

int permute(int ar[]) {
	int i, x, tmp;					// load next descending 
	for (i = 9; i && ar[i-1] <= ar[i]; --i);	// ordered permutation
	if (!i)
		return 0;
		
	for (x = 9; ar[x] >= ar[i-1]; --x);
		
	swap(ar[i-1], ar[x]);
		
	for (x = 9; i < x; ++i, --x) 
		swap(ar[i], ar[x]);
	
	return 1;
}

int main() {
	int num[] = {10,9,8,7,6,5,4,3,2,1};
	int *sol[15];
	
	const int ref[] = { 4, 7, 10, 13, 14 };         // copied indicies
	const int refi[] = { 2, 4, 6, 8, 1 };           // shared source indices
	int i, r = 0;
	for (i = 0; i < 15; ++i)			// align pointers to form 'magic 5 gon'
		if (i == ref[r])
			sol[i] = &num[refi[r++]];
		else
			sol[i] = &num[i-r];

	int sum[5], c;
	do {
		c = 1;
		for (i = 3; c && i <= 12; i += 3)	// skip permutations where first line
			if (*sol[0] > *sol[i])		// is not smallest
				c = 0;
				
		if (c) {
			for (i = 0; i < 5; ++i)		// zero sum for addition
				sum[i] = 0;
				
			for (i = 0; i < 15; ++i) 	// sum each line
				sum[i/3] += *sol[i];
			
			for (i = 0; c && i < 4; ++i)	// compare sums
				if (sum[i] != sum[i+1])
					c = 0;
		}
	} while (!c && permute(num));

	for (i = 0; i < 15; ++i)			// first permutation passing all tests
		printf("%d", *sol[i]);			// = win
	putchar(10);
}



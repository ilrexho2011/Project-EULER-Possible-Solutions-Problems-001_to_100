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

Pergjigja e sakte eshte: 6531031914842725	*/

#include <iostream>
#include <Vector>
#include <algorithm>
#include <string>  
#include <ctime> 

using namespace std;
typedef unsigned long long ui;
int a[] = { 10,1,2,3,4,5,6,7,8,9 };

int s(int q, int w, int e) {
	return(a[q] + a[w] + a[e]);
}
int prod(int q, int w, int e) {
	return(a[q] * 100 + a[w] * 10 + a[e]);
}
void p(int q, int w, int e, bool last = false) {
	if (last)cout << a[q] << "," << a[w] << "," << a[e] << "\n";
	else cout << a[q] << "," << a[w] << "," << a[e] << "; ";
}

void equ(int(&x)[5]) {
	x[0] = prod(0, 6, 7);
	x[1] = prod(1, 7, 8);
	x[2] = prod(2, 8, 9);
	x[3] = prod(3, 9, 5);
	x[4] = prod(4, 5, 6);
	//sort(x, x + 3);
}

ui fin(int(&x)[15]) {
	ui p = 0;
	for (size_t i = 0; i < 15; i++)
	{
		p *= 10;
		if (a[x[i]] == 10)p *= 10;
		p += a[x[i]];
	}
	return p;
	//sort(x, x + 3);
}
int main() {
	clock_t	startTime = clock();
	
	int A, B, C, D, E;
	int res[5] = { 0 };
	ui largest = 0, smallest, stored, all, toPrint;
	int y[15] = { 0,6,7, 1,7,8, 2,8,9, 3,9,5, 4,5,6 };
	while (next_permutation(a+1, a + 10))
	{
		A = s(0, 6, 7);
		B = s(1, 7, 8);
		C = s(2, 8, 9);
		D = s(3, 9, 5);
		E = s(4, 5, 6);
		if (A==B && B==C && C==D && D==E) {

			equ(res);

			smallest = a[y[0]];	stored = 0;
			for (int i = 0; i < 5; i++)
			{
				rotate(y, y + 3, y + 15);
				if (a[y[0]] <= smallest) {
					smallest = y[0]; stored = i;
				}
			}

			for (int i = 0; i <= stored; i++)
				rotate(y, y + 3, y + 15);

			toPrint = fin(y);

			if (toPrint > largest)
				largest = toPrint;
		}
	}
	cout << toPrint << endl;

	cout << to_string(double(clock() - startTime) / (double)CLOCKS_PER_SEC ) << " seconds." << endl;

	system("pause");
}



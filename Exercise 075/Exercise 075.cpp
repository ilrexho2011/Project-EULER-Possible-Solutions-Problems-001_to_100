/*  Singular integer right triangles

Problem 75 It turns out that 12 cm is the smallest length of wire that can be bent to form an integer 
sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5) 24 cm: (6,8,10) 30 cm: (5,12,13) 36 cm: (9,12,15) 40 cm: (8,15,17) 48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, 
and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly 
three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?

Pergjigje: 161667  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

#define MAX 2000000

int coprime(int a, int b) {
    int t;

    while (b) {
	t = b;
	b = a%b;
	a = t;
    }

    if (a == 1)
	return 1;
    else
	return 0;
}

int main(void) {
    int m, n, nt = 0, k, maxn;
    int lst[MAX/2];

    bzero(lst, MAX/2*sizeof(int));

    maxn = ((int)sqrt((double)(4*MAX))-3)/4 + 1;

    for(n = 1; n < maxn; n++)
	for (m = n+1; 2*(m*n + m*m) <= MAX; m += 2) {
	    if (coprime(m, n))
		for (k = 1; 2*k*(m*n+m*m) <= MAX; k++) {
		    nt++;
		    lst[k*(m*m+m*n)-1] += 1;
		}
	}

    m = 0;
    for (n = 0; n < MAX/2; n++)
	if (lst[n] == 1)
	    m++;
    
    printf("There are %d perimeters containing exactly "
           "one of the %d triplets.\n", m, nt);

    return 0;
}
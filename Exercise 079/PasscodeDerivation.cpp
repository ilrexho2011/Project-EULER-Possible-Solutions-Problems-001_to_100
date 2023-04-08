/*   Passcode derivation
 
Problem 79
A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.


Pergjigje:  73162890    */


#include <stdio.h>
#include <time.h>

int main() {
	clock_t start = clock();
	int i, j, k, a, curr, works, workCode, codes[50];

	FILE *fp = fopen("p79.txt", "r");

	for (i = 0; i < 50; i++)
		fscanf(fp, " %d ", codes + i);

	fclose(fp);

	for (i = 100; i > 0; i++) {
		works = 1;
		for (j = 0; j < 50; j++) {
			curr = codes[j];
			k = i;
			for (a = 0; a < 3; a++) {
				workCode = 0;

				while (k > 0) {
					if (k % 10 == curr % 10) {
						workCode = 1;
						break;
					}

					k /= 10;
				}

				if (!workCode) {
					works = 0;
					break;
				}

				k /= 10;
				curr /= 10;
			}

			if (!works)
				break;
		}

		if (works)
			break;
	}

	printf("Answer: %d\nTime taken: %g seconds\n", i, (double) (clock() - start) / CLOCKS_PER_SEC);

	return 0;
}

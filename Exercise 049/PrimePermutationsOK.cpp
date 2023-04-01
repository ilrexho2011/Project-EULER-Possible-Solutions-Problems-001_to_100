/* Prime permutations
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms 
increases by 3330, is unusual in two ways: (i) each of the three terms 
are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence? 
returns the answer 296962999629  */

#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;

int isPermut(int[], int[]);
void extractDigit(int, int[]);
int isPrime(int);

int main()
{
	clock_t before;
	double result;
	before = clock();

	static int answer[1];
	int answerNum = 0;
	int array[4];
	int compare[4];
	
	for (int i = 1000; i <= 3339; i++) {
		int nextNum;
		int foundAnswer = 1;
		if (isPrime(i) == 0)
			continue;
		extractDigit(i, array);
		nextNum = i;
		for (int j = 0; j <= 1; j++) {
			nextNum += 3330;
			if (isPrime(nextNum) == 0) {
				foundAnswer = 0;
				break;
			}
			extractDigit(nextNum, compare);
			if (isPermut(array, compare) == 0) {
				foundAnswer = 0;
				break;
			}
		}
		if (foundAnswer == 0)
			continue;

		answer[answerNum] = i;
		answerNum++;
	}
	result = (double)(clock() - before) / (CLOCKS_PER_SEC/1000);

	cout << "Time taken : " << result << "ms" << endl;

	for (int i = 0; i < answerNum; i++)
		cout << answer[i] << answer[i] + 3330 << answer[i] + 6660 << endl;
	return 0;
}

int isPermut(int arr0[], int arr1[]) {
	for (int i = 0; i < 4; i++) {
		if (arr0[i] != arr1[i])
			return 0;
	}
	return 1;
}

void extractDigit(int number, int array[]) {
	for (int i = 0; i < 4; i++){
		array[i] = number % 10;
		number /= 10;
	}
	for (int i = 0; i < 3; i++) 
		for (int j = i+1; j < 4; j++)
		{
			int temp;
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
}

int isPrime(int number) {
	if (number <= 1)
		return 0;
	for (int i = 2; i < sqrt(number); i++)
		if (number % i == 0 && number != 2)
			return 0;
	return 1;
}

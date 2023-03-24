/* Truncatable primes
The number 3797 has an interesting property. Being prime itself, 
it is possible to continuously remove digits from left to right, 
and remain prime at each stage: 3797, 797, 97, and 7. Similarly 
we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable 
from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes. 
returns the answer 748317  */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function declaration:
void primeVector(double[], int);
// primeVector - Generate a vector of prime numbers.
// @ param = double[] - Vector to store number
// @ param = int - number of elements to be calculated

// Main Function Definition:
int main(){
	int number;
	
	// Ask politely for user input:
	cout << "Enter the number of primes to be generated: ";
	cin >> number;
	
	double vector[number];
	
	// Generate prime vetor:
	primeVector(vector,number);
	
	// Print last number:
	cout << "The biggest prime number is: " << vector[(number-1)] << endl;
	
	// Support variables:
	double remainder;
	int countDigits;
	int flag1;
	int flag2;
		
	// Algorithm Variables: 
	double digits[7] = {0,0,0,0,0,0,0};
	
	for(int i=0; i<number; ++i){
		// Set initial values:
		countDigits = 0;
		remainder = vector[i];
		while(remainder>0.5	){
			digits[countDigits] = (remainder-(10*(floor((remainder/10)))));
			remainder = (remainder-digits[countDigits])/10;
			countDigits += 1;
		}
		
		// Now that we have the digits:  
		double number2;
		number2 = 0;
		for(int j=0; j<countDigits; ++j){
			flag1 = 0;	
			number2 += digits[j]*pow(10,j);
			for(int l=0; l<number; ++l){
				if(number2<vector[l]) break;
				if(number2==vector[l]) flag1 = 1;
			}
			if(flag1 == 0) break;
		}
		number2 = 0;
		for(int j=(countDigits-1); j>=1; --j){
			flag2 = 0;	
			flag2 = 0;	
			number2 = (number2*10) + digits[j];
			for(int l=0; l<number; ++l){
				if(number2<vector[l]) break;
				if(number2==vector[l]) flag2 = 1;
			}
			if(flag2 == 0) break;
		}
		
		// Increase count:
		if(flag1 == 1){
			if(flag2 == 1){
				cout << vector[i] << " is special prime" << endl;
			}
		}
		// Put digit vector back to zero:
		for(int j=0; j<7; ++j) digits[j] = 0;
	}
	return(0);
}

// Function definiton:
void primeVector(double vectorInput[], int number){
	// Pre-allocate counters:
	int countPrimes = 2;
	int countPrime2 = 2;
	double count = 5;
	double addCount = 2;
	// Pre Allocate:
	double compPrime = 9;
	double teste1;
	double teste2;
	// Flag for primes;
	int flag;
	// Pre Allocate first Values:
	vectorInput[0] = 2;
	vectorInput[1] = 3;
	
	while(countPrimes < number){
		// Restart Flag 
		flag = 1;
		
		// If count is greater is than compPrime
		if(count > compPrime){
			countPrime2 += 1;
			compPrime = pow(vectorInput[countPrime2],2);
		}
		// See if it is prime by dividing:
		for(int i=0; i<=countPrime2; ++i){
			teste1 = count/vectorInput[i];
			teste2 = teste1 - floor(teste1);
			if(teste2 == 0){
				flag = 0;
				break;
			}
		}
		// If flag is 1, than update vector:
		if(flag == 1){
			vectorInput[countPrimes] = count;
			countPrimes += 1;
		}
		// Update count:
		count +=  addCount;
		if(addCount == 2){
			addCount = 4;
		}else{
			addCount = 2;
		}
	}
}

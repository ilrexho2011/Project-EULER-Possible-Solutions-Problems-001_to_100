#include <iostream>
#include <math.h>
#include <vector>

//Project Euler problem 12
//Have to find first triangle number with 500 divisors

/*
    Stuff that might help:
    Prime numbers have two factors
    Perfect squares have odd number of factors
    All other numbers have an even number of factors
    Dividing a number by one of its factors will make it 
    smaller while still allowing to find all factors
    All numbers can be broken up by prime factorization
*/

/*
1. Program will first create an array of primes up to 2000000
2. Program will create a triangle number
3. Program will find prime factorization of triangle number
4. Program will calculate number of factors based on prime factorization
5. Program will output triangle number if 500 or more factors and then exit, otherwise go to 2 with a larger triangle number
*/

long long int findTriangleNumber(long long int n);
unsigned long int * primeSieve(unsigned long int *arrayAddress, unsigned long int arraySize);
unsigned int * findPrimeFactors(unsigned long int *primeArrayAddress, unsigned long int primeArraySize, unsigned int *primeFactorArrayAddress, unsigned long int factorsArraySize, unsigned long long int triangleNumber);
int findNumberOfFactors(unsigned int *primeFactors, int factorArraySize);

int main () {

    //INITIALIZATION------------------------------------------------------------------------------------------------------------------------------------
    unsigned long long int triangleNumber;
    int numberOfFactors;
    unsigned long int primeArraySize = 20000;                                 //Max number that primes should be generated up to
    unsigned int factorArraySize = 1000;                                        //Max number of prime Factors allowed
    unsigned long int * primeArray = new unsigned long int [primeArraySize];    //Storage for prime numbers
    unsigned int * primeFactors = new unsigned int [factorArraySize];             //Storage from prime factors
    primeArray[0] = 0;                                                          //Optimization stuff. Don't worry about it unless it seems to break something
    primeArray[1] = 0;                                                          //same as above

    for (long long int i = 2; i < primeArraySize; i++){                         //Initialize values for prime number array
        primeArray[i] = i;
    }

    for (int i = 0; i < 1000; i++) {                                            //Initialize all values of primeFactors to 0
        primeFactors[i] = 0;
    }

    //FIND PRIME NUMBERS------------------------------------------------------------------------------------------------------------------------
    primeArray = primeSieve(primeArray, primeArraySize);    //Sieve out all the non-prime numbers

    /*for (int i = 0; i < primeArraySize; i++) {  //Print out prime numbers
        if (primeArray[i] != 0) std::cout << primeArray[i] << std::endl;
    }*/

    for (int i = 2; i < 999999; i++){

        //CALCULATE TRIANGLE NUMBER------------------------------------------------------------------------------------------------------------------------

        triangleNumber = findTriangleNumber(i);

        //FIND FACTORS OF TRIANGLE NUMBER------------------------------------------------------------------------------------------------------------------------

        primeFactors = findPrimeFactors(primeArray, primeArraySize, primeFactors, factorArraySize, triangleNumber);

        /*for (int i = 0; i < factorArraySize; i++){
            if (primeFactors[i]) std::cout << primeFactors[i] << std::endl;
        }*/

        //FIND NUMBER OF FACTORS------------------------------------------------------------------------------------------------------------------------

        numberOfFactors = findNumberOfFactors(primeFactors, factorArraySize);

        //std::cout << i << ": There are a total of " << numberOfFactors << " factors for " << triangleNumber << std::endl;

        for (int i = 0; i < 1000; i++) {                                            //all values of primeFactors to 0
            primeFactors[i] = 0;
        }

        if (numberOfFactors >= 500){
            std::cout << "Found solution: " << numberOfFactors << " factors for " << triangleNumber << ", index " << i << std::endl;
            break;
        }

    }

    //std::cout << findTriangleNumber(primeArraySize);
    return 0;
}

long long int findTriangleNumber (long long int n) {    //Finds value of a triangle number given the index of triangle numbers
    return (n*(n+1))/2;
}

unsigned long int * primeSieve(unsigned long int *arrayAddress, unsigned long int arraySize){  //finds primes up to arraySize-1
    bool isPrime[arraySize];                                                    //Array for saying if a value in an array index is prime or not
    for (unsigned long int i = 0; i < arraySize; i++) isPrime[i] = true;        //Initialize isPrime array

    for (unsigned long int i = 2; i < arraySize; i++){                          //Figure out if numbers are prime, assign each index true or false
        if (isPrime[i]){
            for (unsigned long int j = i*2; j < arraySize; j += i){
                isPrime[j] = false;
                arrayAddress[j] = 0;                        //Changes non-prime numbers to 0
            }
        }
    }

    arrayAddress[arraySize-1] = 0;  //Assign 0 at the end of array

    unsigned long int lIndex = 0;   //left index for removing 0s from array
    unsigned long int rIndex = 1;   //right index for removing 0s from array
    while (rIndex < arraySize){     //Starting from the left of the prime array, if a value at an index is 0,
                                    //assign the nearest non-zero value to the right to that index, and change
                                    //the non-zero value to the right to zero
        if (arrayAddress[lIndex] == 0){
            if (arrayAddress[rIndex] != 0){
                arrayAddress[lIndex] = arrayAddress[rIndex];
                arrayAddress[rIndex] = 0;
                rIndex++;
                lIndex++;
            }
            else {
                rIndex++;
            }
        }
        else {
            lIndex++;
        }
    }
    return arrayAddress;
}

unsigned int * findPrimeFactors(unsigned long int *primeArrayAddress, unsigned long int primeArraySize, unsigned int *primeFactorArrayAddress, unsigned long int factorsArraySize, unsigned long long int triangleNumber){
    int factorCounter = 0;
    //std::cout << "Triangle number starts as " << triangleNumber << std::endl;
    for (int i = 0; i < 10000; i++){
        if (triangleNumber == 1){
            //std::cout << "Triangle number is now " << triangleNumber << ". Breaking.\n";
            break;
        }
        if (triangleNumber%primeArrayAddress[i] == 0){
            primeFactorArrayAddress[factorCounter] = primeArrayAddress[i];
            triangleNumber /= primeArrayAddress[i];
            //std::cout << "Triangle number is now " << triangleNumber << ". Divided by " << primeArrayAddress[i] <<  std::endl;
            i = -1;
            factorCounter++;
        }
    }

    //std::cout << "Finished factoring\n";

    /*for (int i = 0; i < factorCounter; i++){
        std::cout << primeFactorArrayAddress[i] << std::endl;
    }*/

    //std::cout << "There are " << factorCounter << " prime factors\n";

    return primeFactorArrayAddress;
}

int findNumberOfFactors(unsigned int *primeFactors, int factorArraySize){
    std::vector<int> factors;
    std::vector<int> uniqueFactors;
    int totalFactors = 1;

    for (int i = 0; i < factorArraySize; i++){
        if (primeFactors[i] != 0) factors.push_back(primeFactors[i]);
    }

    uniqueFactors.push_back(factors[0]);    //Needed for next block

    for (int i = 0; i < factors.size(); i++){
        //std::cout << factors[i] << std::endl;
        for (int j = 0; j < uniqueFactors.size(); j++){
            if (factors[i] == uniqueFactors[j]){
                break;
            }
            if (j == uniqueFactors.size()-1 && factors[i] != uniqueFactors[j]){
                uniqueFactors.push_back(factors[i]);
                //std::cout << "Adding to uniqueFactors\n";
            }
        }
    }

    //std::cout << "Size of uniqueFactors is: " << uniqueFactors.size() << std::endl;

    //for (int i = 0; i < uniqueFactors.size(); i++) std::cout << uniqueFactors[i] <<std::endl;

    int * factorCounter = new int [uniqueFactors.size()];
    for (int i = 0; i < uniqueFactors.size(); i++) factorCounter[i] = 1;

    for (int i = 0; i < uniqueFactors.size(); i++){
        for (int j = 0; j < factors.size(); j++){
            if (uniqueFactors[i] == factors[j]) factorCounter[i]++;
        }
    }

    for (int i = 0; i < uniqueFactors.size(); i++) totalFactors *= factorCounter[i];

    return totalFactors;
}

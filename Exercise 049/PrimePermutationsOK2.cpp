/* Prime permutations
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms 
increases by 3330, is unusual in two ways: (i) each of the three terms 
are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, 
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence? 
returns the answer 296962999629  */

#include <iostream>

using namespace std;

/**
 * Given an array of integers a, swaps the
 * ith element with the jth element.
 */
void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

/**
 * Given an integer array of length 4, sort the array.
 * 
 * This mutates the array a passed to selectionSort.
 */
void selectionSort(int a[]) {
    for (int i = 0; i < 3; i++) {
        int min = i;
        for (int j = i + 1; j < 4; j++) {
            if (a[min] > a[j]) min = j;
        }
        swap(a, i, min);
    }
}

// https://en.wikipedia.org/wiki/Primality_test#Pseudocode
bool isPrime(int n) { 
    if (n <= 1) return false;
    if (n <= 3) return true;
    if ((n % 2 == 0) || (n % 3 == 0)) return false;
    int i = 5;
    while (i * i <= n) {
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
        i += 6;
    }
    return true;
}

/**
 * Do the given arrays a and b have the same values in the same indexes?
 */
bool arrayEquals(int a[], int b[]) {
    for (int i = 0; i < 4; i++) if (a[i] != b[i]) return false;
    return true;
}

/**
 * Given an integer and a placeholder array of length 4, copies the
 * digits from the integer to the indexes of the placeholder array.
 * 
 * This mutaties the array aux passed to itoa.
 */
void itoa(int a, int aux[]) {
    for (int i = 3; i > -1; i--) {
        aux[i] = a % 10;
        a /= 10;
    }
}

/**
 * Are the given integers i, j, and k permutations of
 * each other's digits?
 */
bool arePerms(int i, int j, int k) {
    int a[4];
    int b[4];
    int c[4];
    itoa(i,a);
    itoa(j,b);
    itoa(k,c);
    selectionSort(a);
    selectionSort(b);
    selectionSort(c);
    return (arrayEquals(a,b) && arrayEquals(b,c));
}

/**
 * Prints the concatenation of the three 4-digit numbers which are:
 * (1) Sequential terms in an arithmetic sequence,
 * (2) All prime, and
 * (3) Permutations of the other.
 * 
 * E.g., since one such solution to the above criteria is set of numbers
 * 1487, 4817, 8147, solve() prints 148748178147.
 */
void solve() {
    
    /** We know that all numbers must be four digits, hence start above
     * 999, and we know that all must be prime, so begin with an odd
     * number and increment by 2.
     */
    for (int begin = 1001; begin < 10000; begin += 2) {
        
        // Fail early to avoid costly additional computation.
        while (!isPrime(begin)) {
            begin += 2;
        }
        
        /** Since we know that all numbers must be four digits, we only
         * add `dist` until the largest number is 5 digits.
         * Since we know that all numbers must be prime, and that our
         * first number is prime, we can only add even numbers to reach
         * other primes, so increment `dist` by 2 each time.
         */
        for (int dist = 2; (begin + 2*dist) < 10000; dist += 2) {
            
            // If the other two numbers are prime
            if (isPrime(begin+dist) && isPrime(begin+2*dist)) {
                
                // And all three numbers are permutations
                if (arePerms(begin, begin+dist, begin+2*dist)) {
                    
                    // We output an answer
                    cout << begin << begin+dist << begin+2*dist << endl;
                }
            }
        }
    }
}

int main() {
    solve();
    return 1;
}

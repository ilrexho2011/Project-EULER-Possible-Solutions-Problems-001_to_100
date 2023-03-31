//  Sub-string divisibility
/*	The number, 1406357289, is a 0 to 9 pandigital number because 
it is made up of each of the digits 0 to 9 in some order, 
but it also has a rather interesting sub-string divisibility property.
Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, 
we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
Pergjigja e sakte eshte: 16695334890  */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

long long fak(int i){
    if(i == 1) return 1;
        else return i*fak(i-1);
}

int get_substring(int n[], int b){
    return n[b-1]+(10*n[b-2])+(100*n[b-3]);
}

double get_value(int n[]){
    double sum = 0;
    for(int i = 9; i >= 0; i--){
        sum += n[i] * pow(10, 9-i);
    }
    return sum;
}

int main(){
    double sum = 0;
    long long m = fak(10);
    int a[] = {1, 4, 0, 6, 3, 5, 7, 2, 8, 9};
    for(int i = 1; i < m; i++){
        if(get_substring(a, 10)%17 == 0){
            if(get_substring(a, 9)%13 ==0){
                if(get_substring(a, 8)%11 ==0){
                    if(get_substring(a, 7)%7 ==0){
                        if(get_substring(a, 6)%5 ==0){
                            if(get_substring(a, 5)%3 ==0){
                                if(get_substring(a, 4)%2 ==0){
                                    sum+=get_value(a);
                                }
                            }
                        }
                    }
                }
            }
        }
        next_permutation(a, a+10);
    }
    cout << setprecision(12) << sum;
    return 0;
}

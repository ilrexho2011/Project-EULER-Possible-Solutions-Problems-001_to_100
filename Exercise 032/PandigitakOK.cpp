/* We shall say that an n-digit number is pandigital if it makes use 
of all the digits 1 to n exactly once; for example, the 5-digit number, 
15234, is 1 through 5 pandigital.
The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing 
multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity 
can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only 
include it once in your sum. 
def ispandigital(s):
	return s==s[::-1]
nums=set()
for i in range(123,9876):
	l=divisors(i)
	for d in l:
		e=i/d
		if e in l and ispandigital(str(d)+str(e)+str(i)):nums.add(i)

print sum(nums)
This code returns the answer 45228 in 0.275868 seconds.
The pandigital function really shows python's string handling capabilites. 
The syntax s[a:b:k] slices the string (sequence of characters) from a to b 
with step k. For example, if I have the string s="abcdef". 
If I take s[1:5:2], it starts at 'b", then takes two steps forward, 
giving "bd" Two steps later, the index would be 6, so that one isn't included. 
If we don't enter values for a and b, the whole string is take. Using -1 as step, 
Python will get the string backwards, so s[::-1] produces "fedcba".
What I did in the code was simply use a set (to avoid multiple combinations) 
and then check for all divisor pairs of the number whether they made a pandigital.*/

#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<numeric>

using namespace std;

int main(){
	int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int product;
	int multi;
	int cand;
	int product2;
	int multi2;
	int cand2;
	int total = 0;
	list<int> products;

	do {
		
		multi = nums[0]*10 + nums[1];
		cand = nums[2]*100 + nums[3]*10 + nums[4];
		product = nums[5]*1000 + nums[6]*100 + nums[7]*10 + nums[8];
		
		multi2 = nums[0];
		cand2 = nums[1]*1000 + nums[2]*100 + nums[3]*10 + nums[4];
		product2 = nums[5]*1000 + nums[6]*100 + nums[7]*10 + nums[8];

		if (multi*cand == product) {
			products.insert(products.end(),product);
			
			}
		if (multi2*cand2 == product2) {
			products.insert(products.end(),product2);
			}

	} while(next_permutation(nums,nums + 9)); 
	
	products.sort();
	products.unique();

	total = accumulate(products.begin(),products.end(),0);


	cout << total << "\n";

	return 1;
}

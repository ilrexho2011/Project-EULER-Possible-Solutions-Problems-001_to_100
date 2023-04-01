//	Goldbach's other conjecture
/*	It was proposed by Christian Goldbach that every odd composite number 
can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.
What is the smallest odd composite that cannot 
be written as the sum of a prime and twice a square?
Pergjigja e sakte eshte: 5777	*/

#include <iostream>
using namespace std;
const int mx = 100000;
int main(){
	bool p[mx] = {};
	p[0] = p[1] = 1;
	for(int i = 2; i < mx; ++i) if(!p[i])
		for(int j = i+i; j < mx; j += i) p[j] = 1;
	for(int i = 9;;i += 2) if(p[i]){
		bool win = 1;
		for(int j = 1; 2*j*j < i; ++j) if(!p[i-2*j*j]) win = 0;
		if(win){
			cout << i << endl;
			break;
		}
	}
}

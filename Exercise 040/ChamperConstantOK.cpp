/* Champernowne's constant
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

returns the answer 210  */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string intToString(long long a){
  stringstream ss;
  ss << a;
  string str = ss.str();
  return str;
}

int main(){
  string a="0";
  for(long long i=1;i<=100000;i++){
    a=a+intToString(i);
  }
  cout << (a[1]-48)*(a[10]-48)*(a[100]-48)*(a[1000]-48)*(a[10000]-48)*(a[100000]-48) << endl;
}

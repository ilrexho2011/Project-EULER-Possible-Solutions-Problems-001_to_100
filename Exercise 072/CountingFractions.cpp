/*  Counting fractions
 
Problem 72
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?

Pergjigje:  303963552391  */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 unsigned int* lpf;
 unsigned int* totient;
 lpf = new unsigned int [1000001];
 totient = new unsigned int [1000001];
 //step 1: fill the lpf array
 memset(lpf, 0, 4000004);
 memset(totient, 0, 4000004);
 unsigned int cur = 2;
 while (cur < 1000)
 {
  if (lpf[cur] == 0)
  {
   for (unsigned int i = cur; i < 1000001; i += cur)
   {
    if (lpf[i] == 0) lpf[i] = cur;
   }
  }
  cur++;
 }
 while (cur < 1000001)
 {
  if (lpf[cur] == 0) lpf[cur] = cur;
  cur++;
 }
 //step 2: at each number from 2 to 1000000, divide out all powers of lpf first
 cur = 2;
 while (cur < 1000001)
 {
  unsigned int tempcur;
  unsigned int curexp;
  tempcur = cur;
  curexp = 0;
  while (tempcur % lpf[cur] == 0)
  {
   tempcur = tempcur / lpf[cur];
   curexp++;
  }
  if (tempcur == 1) totient[cur] = pow((int)lpf[cur], (int)curexp) - pow((int)lpf[cur], (int)curexp - 1);
  else totient[cur] = (pow((int)lpf[cur], (int)curexp) - pow((int)lpf[cur], (int)curexp - 1)) * totient[tempcur];
  cur++;
 }
 //step 3: add all totient values
 unsigned __int64 sum = 0;
 cur = 2;
 while (cur < 1000001)
 {
  sum += totient[cur];
  cur++;
 }
 cout << sum << endl;
 system("pause");
 delete [] lpf;
 delete [] totient;
}
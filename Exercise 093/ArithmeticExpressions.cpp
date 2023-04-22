/*   Arithmetic expressions

Problem 93
By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, −, *, /) and brackets/parentheses, it is possible to form different positive integer targets.

For example,

8 = (4 * (1 + 3)) / 2
14 = 4 * (3 + 1 / 2)
19 = 4 * (2 + 3) − 1
36 = 3 * 4 * (2 + 1)

Note that concatenations of the digits, like 12 + 34, are not allowed.

Using the set, {1, 2, 3, 4}, it is possible to obtain thirty-one different target numbers of which 36 is the maximum, and each of the numbers 1 to 28 can be obtained before encountering the first non-expressible number.

Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be obtained, giving your answer as a string: abcd.


Pergjigje:  1258   */

// Project Euler  Problem 093

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <map>
#include <set>
using std::cout;

typedef std::map<int, std::set<int> > TMap;
TMap S;

enum eOperation
{
	ePlus,
	eMinus,
	eMul,
	eDiv
};

class ExDivByZero : public std::exception
{};

double op(const double x1, const double x2, int z)
{
	double r = 0;
	switch(z)
	{
		case ePlus  : r = x1 + x2; break;
		case eMinus : r = x1 - x2; break;
		case eMul   : r = x1 * x2; break;
		case eDiv	: 
		{
			if( x2 == .0)
				throw ExDivByZero();
			else
				r = x1 / x2;
		}
	}
	return r;
}

bool IsInteger(double d)
{
	return (ceil(d) == d);
}

int mask(int a, int b, int c, int d)
{
	int r = 0;
	int m[10] = {0,};
	m[a] = m[b] = m[c] = m[d] = 1;
	for(int i = 0; i < 10 ; i++)
		if(m[i])
			r = r*10, r+=i;
	return r;
}

int f(	double& a1, double& b1, int op1, double& x1, 
		double& a2, double& b2, int op2, double& x2, 
		double& a3, double& b3, int op3)
{
	double r = 0;
	try
	{
		x1 = op(a1, b1, op1);
		x2 = op(a2, b2, op2);
		r =  op(a3, b3, op3);
	}
	catch(ExDivByZero& e)
	{}
	if(!IsInteger(r))
		r = 0;
	
	return (int)r;
} 

int test(int _a, int _b, int _c, int _d)
{
	int m = mask(_a, _b, _c, _d);
	double a = _a, b = _b, c = _c, d = _d;
	double x1, x2;
	int r;
	for(int e1 = ePlus; e1 <= eDiv; e1++)
		for(int e2 = ePlus; e2 <= eDiv; e2++)
			for(int e3 = ePlus; e3 <= eDiv; e3++)
			{
				r = f(a, b, e1, x1,  x1, c, e2, x2,  x2, d, e3);
				if(r > 0) S[m].insert(r);
				
				r = f(b, c, e1, x1,  a, x1, e2, x2,  x2, d, e3);
				if(r > 0) S[m].insert(r);
				
				r = f(b, c, e1, x1,   x1, d, e2, x2,  a, x2, e3);
				if(r > 0) S[m].insert(r);
				
				r = f(c, d, e1, x1,  b, x1, e2, x2,  a, x2, e3);
				if(r > 0) S[m].insert(r);
				
				r = f(a, b, e1, x1,  c, d, e2, x2,  x1, x2, e3);
				if(r > 0) S[m].insert(r);
								
			}
	return 0;
}

bool AllDiff(int a, int b, int c, int d)
{
	int n[10] = {0,};
	n[a]++; n[b]++; n[c]++; n[d]++;
	for(int i = 1; i <= 9; i++)
		if(n[i] > 1)
			return false;
	
	return true;
}

long task93()
{
	for(int a = 1; a <= 9; a++)
		for(int b = 1; b <= 9; b++)
			for(int c = 1; c <= 9; c++)
				for(int d = 1; d <= 9; d++)
					if(AllDiff(a, b, c, d))
						test(a, b, c, d);

	int max_len = 0;
	int max_mask = 0;						
	for(TMap::iterator it = S.begin(); it != S.end(); it++)
	{
		int m = it->first;
		cout << " " << m << " : ";
			
		std::set<int> &s2 = it->second;
		int prev = 0;
		int len = 0;
		for(std::set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
		{
			if(*it2 == prev+1)
				len++;
			else
				break;

			prev = *it2; cout << *it2 << " ";
		}
		cout << " :" << len << "\n";
		if(len > max_len)
			max_len = len, 	max_mask = m;
	}
	return max_mask;
}

int main()
{
	cout << "\ntask 93 pergjigje: " << task93();
	return 0;
}
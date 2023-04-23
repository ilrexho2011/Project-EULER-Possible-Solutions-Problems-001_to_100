/*    Almost equilateral triangles

Problem 94
It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.

Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).

Pergjigje:  518408346   */

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

typedef long long int lint;

lint sqrt(lint n)
{
	lint r1=n;
	lint r2=n/2;
	if (r2==0)
		r2=1;
	while(r1-r2>0)
	{
		r1 = r2;
		r2=(r1+n/r1)/2;
	}
	return r1;
}

const double COEF = 2.0+sqrt(3.0);

int main()
{
	lint a1=0,s=0;
	int addi=-1;
	for(lint a=10; a<1000000000/3; a-=2*addi)
	{
		a1 = (a/2+addi)*(3*a/2+addi);
		if (sqrt(a1)*sqrt(a1) == a1)
		{
			s += 3*a-2;
			a = int(double(a)*COEF)+(addi+1)/2;
			addi = -addi;
		}
	}
	cout << s << endl;
}
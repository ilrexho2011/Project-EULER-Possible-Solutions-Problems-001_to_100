/* Integer right triangles
If p is the perimeter of a right angle triangle with integral 
length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p = 1000, is the number of solutions maximised?
returns the answer 840  */

#include<iostream>
#include<ctime>

using namespace std;

bool TriangleInt(int a, int b, int c);

int main()
{
	int num = 5;
	int c;
	int counter = 0;
	int maxTriangles = 0;
	int maxCount = 0;
	while (num < 1000)
	{
		counter = 0;
		for (int i = 1; i < num; i++)
		{
			for (int j = num - 1; j > i; j--)
			{
				c = num - (i + j);
				if (TriangleInt(i, j, c))
				{
					counter++;
				}
			}
		}
		if (counter > maxCount)
		{
			maxTriangles = num;
			maxCount = counter;
		}
		num++;
	}
	cout << maxTriangles << endl;
	cout << clock() << endl;
	system("pause");
	return 0;
}

bool TriangleInt(int a, int b, int c)
{
	a *= a;
	b *= b;
	c *= c;
	if (a == b + c)
	{
		return true;
	}
	else if (b == a + c)
	{
		return true;
	}
	else if (c == a + b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

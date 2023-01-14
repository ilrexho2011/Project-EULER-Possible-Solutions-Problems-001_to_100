/*	-------------------------------------------------------------
	Nje triplet Pythagorean eshte nje bashkesi 3 numrash natyror,
	te tille qe a < b < c, ku ka vend qe, a2 + b2 = c2
	Per shembull, 32 + 42 = 9 + 16 = 25 = 52.

	Ekziston saktesisht vetem nje triplet Pythagorean per te cilin 
	a + b + c = 1000. Gjeni produktin e triplletit abc.
	Pergjigja e sakte eshte: 31875000 
	--------------------------------------------------------------*/
#include <iostream>
using namespace std;
int main()
{
	for (int b = 1000; b > 1; b--)
	{
		for (int a = 1; a < 1000; a++)
		{
			if (((1000 - a - b)*(1000 - a - b))==((a*a)+(b*b)))
			{
				cout << " Produkti abc = " << a * b * (1000 - a - b ) << endl;
				return 0;
			}
		}
	}
	return 0;
}

/*	-------------------------------------------------------------
	Nje triplet Pythagorean eshte nje bashkesi 3 numrash natyror,
	te tille qe a < b < c, ku ka vend qe, a2 + b2 = c2
	Per shembull, 32 + 42 = 9 + 16 = 25 = 52.

	Ekziston saktesisht vetem nje triplet Pythagorean per te cilin 
	a + b + c = 1000. Gjeni produktin e triplletit abc.
	Pergjigja e sakte eshte: 31875000 
	--------------------------------------------------------------*/
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;
int main(void) {
    int numero = 0;
    do {

        int a = 1;
        int b = 2;
        int c = 3;
        int totali;

        for (a=1;a<b;a++) 
		{
            for (b=2;b<c;b++) 
			{
                for (c=3;c<=1000;c++) 
				{
                    totali = a+b+c;

                    if (totali == 1000 && a*a + b*b == c*c) 
					{
                        {
							cout << a << ", " << b << ", " << c << endl;
							cout << "Produkti=" << a*b*c << endl;
							cout << "Shuma=" << a+b+c;
							return 0;
						}
                    }
                }
            }
        }



        numero++;

    } while(numero < 1000);  
    getch();
	return 0;
    
}

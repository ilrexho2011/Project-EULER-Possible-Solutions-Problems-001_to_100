/*  --------------------------------
	Te gjendet numri Prim i 10001-te
	Pergjigja e sakte eshte 104743
	--------------------------------*/
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

bool prim (int n)					// Funksion kontrollimi per numrin e rradhes
{
    for (int i=2; i<=sqrt(n); i++)	// Kontrollojme per pjestues deri tek rrenja katrore e numrit
         if ( n%i == 0)
            return 0;
    return 1;
}

int main()
{int j=0;
    for (int i=2;  ; i++)			// Gjenerojme numrat me rradhe
     {   if ( prim (i) )			// Therrasim funksionin e kontrollimit te numrave prim
        	{
				j++;				// Sa here gjendet nje nr prim numeratori j rritet me 1
        	}
	if ( j == 10001 )				// Kontrollojme vleren e numeratorit
			{
    			cout << "---------------------------" << endl;
				cout << "Numri PRIM i 10001-ti eshte" << endl;
				cout << "---------------------------" << endl;
				cout << "Pergjigja = " << i << endl;
    			break;
 			}
    }
    return 0;
}

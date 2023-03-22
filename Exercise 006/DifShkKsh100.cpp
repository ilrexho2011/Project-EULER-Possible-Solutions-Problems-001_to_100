/*  --------------------------------------------------------------------
	Shuma e katroreve te dhjete numrave te pare naturor eshte,
        1^2 + 2^2 + ... + 10^2 = 385
        Katrori i shumes se dhjete numrave te pare naturor eshte,
        (1 + 2 + ... + 10)^2 = 552 = 3025
  	Nderkohe qe diferenca mes katrorit te shumes dhe shumes se katroreve
  	te dhjete numrave te pare natyror eshte 3025 - 385 = 2640.
  	Gjeni diferencen mes katrorit te shumes dhe shumes se katroreve 
	te 100 numrave te pare natyror.          
  	Pergjigja e sakte eshte Dif = 25164150  
	--------------------------------------------------------------------*/

#include <iostream>
#include <Windows.h>
using namespace std;

int ShumaKatror (int a)				// Llogaritet Shuma e katroreve
{									// Argumenti a e mmerr vleren nga nr
    int sum = 0;
    for(int i=1; i<=a; i++)
    sum = sum + i*i;
    return sum;  
}

int KatroriShumes (int a)			// Llogaritet Katrori i Shumes
{									// Argumenti a e mmerr vleren nga nr
    int kat, sum = 0;
    for(int i=1; i<=a; i++)
    sum = sum + i;
    kat = sum * sum;
    return kat;  
}

int main()
{
    int nr,S,K,D;
    cout << "Futni numrin kufi: ";
    cin >> nr;                       // Lexohet vlera kufi nga tastiera
    S = ShumaKatror (nr);			 // Therritet Funksioni i Shumes se katroreve
    K = KatroriShumes (nr);		     // Therritet Funksioni i Katrorit te shumes
    D=K-S;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << "Diferenca mes katrorit te shumes dhe shumes se katroreve te 100 nr. natyror" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
    cout << "Dif = " << D << endl;
    system ("pause");
    return 0;
}


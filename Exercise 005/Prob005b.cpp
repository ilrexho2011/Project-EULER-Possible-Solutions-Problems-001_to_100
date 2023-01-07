/*  ----------------------------------------------------
	Numri me i vogel i pjestueshem me secilin nga numrat 
	qe nga 1 deri 20
	METODA REKURSIVE
	2520 eshte numri me i vogel i cili plotpjestohet 
	nga secili prej numrave nga 1 deri ne 10 .
	Cili eshte Numri me i vogel i pjestueshem 
	me secilin nga numrat nga 1 deri 20?
	Pergjigja e sakte eshte 232792560
	---------------------------------------------------*/

#include <iostream>
#include <Windows.h>						    // E shtuam per te perdorur instruksionin system("pause"); 

using namespace std;

int main()
{
	unsigned long num = 20;					  // E nisim me vleren fillestare 20

	while (1)
	{
		int n = 0;
		for (int i = 1; i <= 20; i++)		// Kontrollojme per 20 numrat e pare natyror
		{
			if (num % i == 0)				      // Kontrollojme plotpjestueshmerine e numrit te rradhes
			{
				
				n++;						            // Rritim numrin e plotpjestuesve
				
			}
		}
		if (n == 20) break;					    // Nderpresim punen nese numri i pjestuesve arrin 20
		num ++;								          // Perndryshe kalojme per kontroll numrin e rradhes
	}

			cout << "--------------------------------------------------" << endl;
			cout << "Numri me i vogel i pjestueshem nga numrat 1 deri 20"<< endl;
			cout << "--------------------------------------------------" << endl;
            cout << "NVP 1-20 = " << num << endl;

	system("pause");
    return 0;
}

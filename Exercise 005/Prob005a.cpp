/*  ----------------------------------------------------
	Numri me i vogel i pjestueshem me secilin nga numrat 
	qe nga 1 deri 20
	METODA primitive me KUSHT TE KOMPONUAR
	2520 eshte numri me i vogel i cili plotpjestohet 
	nga secili prej numrave nga 1 deri ne 10 .
	Cili eshte Numri me i vogel i pjestueshem 
	me secilin nga numrat nga 1 deri 20?
	Pergjigja e sakte eshte 232792560
	---------------------------------------------------*/

#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    for(int n = 1; n!=0; n++){
        if (n%1==0 && n%2==0 && n%3==0 && n%4==0 && n%5==0 
			&& n%6==0 && n%7==0 && n%8==0 && n%9==0 && n%10==0 
			&& n%11==0 && n%12==0 && n%13==0 && n%14==0 && n%15==0 
			&& n%16==0 && n%17==0 && n%18==0 && n%19==0 && n%20==0)
			{
			cout << "--------------------------------------------------" << endl;
			cout << "Numri me i vogel i pjestueshem nga numrat 1 deri 20"<< endl;
			cout << "--------------------------------------------------" << endl;
            cout << "NVP 1-20 = " << n << endl;
            return 0;
        	}
    }
    getch ();
    return 0;
}

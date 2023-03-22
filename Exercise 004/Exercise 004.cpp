/*  -------------------------------------------------------
	Produkti me i madh Palindromik i dy numrave 3 shifror
        Nje numer palindromik lexohet njelloj nga te dyja anet. 
	Numri me i madh palindrome i perftuar nga produkti 
	i dy numrave 2-shifror eshte 9009 = 91 × 99.
	Gjeni numrin me te madh palindrome qe perftohet nga 
	produkti i dy numrave 3-shifror.
	Pergjigja e sakte eshte 906609
	-----------------------------------------------------*/

#include <iostream>
#include <math.h>

using namespace std;

int palindrom(int num)
{
    int num_i_ri = 0;
    int shifra = 0;

    while (num != 0)
    {
        shifra = num % 10;
        num_i_ri = num_i_ri * 10 + shifra;
        num /= 10;
    }

    return num_i_ri;
}

int main()
{
    int n1 = 999;
    int n2 = 999;
    unsigned int n = 0;

    unsigned int MaxProdukt = 0;

    for (; n1>=100; n2--)
    {
        if (n2 < 100)
        { 
            n1--; 
            n2 = 999; 
            continue; 
        }

        if (palindrom(n1*n2) == n1*n2)
        {

            if (MaxProdukt < n1*n2)
                MaxProdukt = n1*n2;
        }
    }
	cout << "--------------------------------------------------" << endl;
	cout << "Produkti me i madh Palindromik i 2 nr. 3 shifror"   << endl;
	cout << "--------------------------------------------------" << endl;
    cout << "Pergjigje = " << MaxProdukt << endl;

    return 0;
}

/* ----------------------------------------------------------------
   Shuma e shumefishave te 3 ose 5 brenda vleres 1000
   Nese do te rendisnim te gjithe num. natyror brenda 10 
   te cilet jane shumefisha te 3 ose 5, do te kishim 3, 5, 6 dhe 9. 
   Shuma e tyre do te ishte 23.
   Te gjendet Shuma e shumefishave te 3 ose 5 poshte vleres 1000.
   Pergjigja e sakte eshte 233168.
   ----------------------------------------------------------------*/

   #include <iostream>
   using namespace std;
int main()
{
    int i,shuma=0;
    
    for(i=0; i<1000; i++)
    {
        if((i%5 == 0)||(i%3 == 0))
        {
            shuma += i;
        }
    }
    cout << "--------------------------------------------------" << endl;
	  cout << "Shuma e shumefishave te 3 ose 5 poshte vleres 1000" << endl;
	  cout << "--------------------------------------------------" << endl;
    cout << "Shuma=" << shuma;
    return 0;
}

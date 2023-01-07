/* ---------------------------------------------------------------------------
   Shuma e numrave te Fibonaccio qe jane çift dhe < 4 000 000
   Çdo term i ri ne sekuencen e numrave te Fibonacci 
   gjenerohet nga mbledhja e dy termave paraardhes. 
   Keshtu duke nisur me 1 dhe 2, 10 termat e pare do te jene:

   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

   Duke kerkuar vetem termat e Fibonaccit vlera e te cileve 
   nuk kalon numrin 4 000 000, te gjendet shuma e termave çift te kesaj serie.
   Pergjigja e sakte eshte 4613732
   --------------------------------------------------------------------------*/
#include <iostream>
#include <conio.h>   
using namespace std; 
long int const n=4000000;
int f0=1, f1=2, f=3; 	// Perftojme 3 elementet e pare te serise
long int shuma=2;
int main() 
{ 
while (f<n)				// Perftojme shumen e elementet te tjere te Fibonacit
{
	f0=f1; 
  f1=f; 
  f=f0+f1;
	if (f%2 == 0) shuma +=f;
} 					
	cout << "--------------------------------------------------" << endl;
	cout << "  Shuma e termave cift te Fibonaccit < 4 000 000  " << endl;
	cout << "--------------------------------------------------" << endl;
  cout << "Shuma=" << shuma << endl;
return 0; 
}

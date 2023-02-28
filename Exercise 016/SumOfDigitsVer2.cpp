#include <string>
#include <iostream>
using namespace std;


int subtract (short num);
	  int  x[302];


int main ()
{

		x[301]=2;
	for (short power=1;power!=1000;power++)
	{
		for (short arraynum=301;arraynum!=0;arraynum--)
		{
			x[arraynum]=x[arraynum] * 2;
			}
		
		for (short arraynum=301;arraynum!=0;arraynum--)
		{	
			
			if (x[arraynum]>9)
				{
					
					subtract(arraynum);
			    }

		}
		
	}

	int sum=0;
	
		for (short arraynum=301;arraynum!=-1;arraynum--)
		{sum = sum +x[arraynum];
		}
		cout<<sum;

	cin.get();
	
	return 0;

}
int subtract (short num)
{
	if (x[num]>9)
	{
		x[num]=x[num]-10;
		x[num-1]=x[num-1]+1;
		
	}
return 0;}

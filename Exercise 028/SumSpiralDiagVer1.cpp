#include<iostream>

using namespace std;

int main ()
{
	long sum=1;
	int multiplier =0;
	int addition=1;
	for (int col=0;col<500;col++)
	{
		multiplier++;
	for (int times = 0;times<4;times++)
		
	{
		
		
		addition += 2*multiplier;
	    
		sum+=addition;
		}
	
	}
	cout<<sum;
	getchar();
	return 0;
}

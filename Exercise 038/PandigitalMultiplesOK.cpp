/*  Pandigital multiples
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 
192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying
 by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, 
 which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that 
can be formed as the concatenated product of an integer 
with (1,2, ... , n) where n > 1? 
returns the answer 932718654   */

#include <stdio.h>
#include <string.h>
#include <math.h>
int huge(long long int pan, long long int n){
	int d=0;
	while(pan){
		d++;
		pan/=10;
	}
	while(n){
		d++;
		n/=10;
	}
	if(d>10)return 1;
	return 0;
}
int fun(long long int pan, long long int n){
	int d=0;
	long long int N=n;
	while(n){
		d++;
		n/=10;
	}

	//printf("ret=%lld\n", (pan*(long long int)pow(10,d)+N));
	return (long long int)(pan*pow(10,d)+N);
}

int isPentagonal(int number) {
    int arr[10];
    for(int i=0;i<10;i++)arr[i]=0;
    while(number){
    	int d = number%10;
    	if(arr[d]==1)return 0;
    	arr[d]=1;
    	number/=10;
    }
    for(int i=1;i<10;i++){
    	if(arr[i]==0) return 0;
    }
    if(arr[0]==1)return 0;
    return 1;
}

int main()
{
	long long int ans, i,j, p,pan,MAX=987654321,maxpan=0;
	int flag=1;
	for(i=1; flag; i++){
		pan=0;
		for(j=1;j<10;j++){
			if(huge(pan,i*j))break;
			pan = fun(pan,i*j);
			//printf("i=%lld, j = %lld, pan=%lld\n",i,j ,pan);
			if(j==2 && pan>MAX) flag=0;
			if(isPentagonal(pan)){
				if(maxpan<pan)maxpan=pan;
				printf("i=%lld,j=%lld, maxpan = %lld\n",i,j,maxpan );
			}
			if(pan>=MAX)break;
		}
	}
}


/* Self powers
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
returns the answer 9110846700   */

#include <stdio.h>

unsigned long long power (unsigned long long x){
	unsigned long long y=x,i;
	for (i=2;i<(x+1);i++){
		y*=x;
		y%=10000000000;}
		return y%10000000000;}
		
main(){
 unsigned long long sonuc=1,i;
 	for (i=2;i<1001;i++){
 		sonuc+=power(i);
		sonuc%=10000000000;}
 printf("%llu\n",sonuc);}

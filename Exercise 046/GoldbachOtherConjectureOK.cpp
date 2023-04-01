//	Goldbach's other conjecture
/*	It was proposed by Christian Goldbach that every odd composite number 
can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.
What is the smallest odd composite that cannot 
be written as the sum of a prime and twice a square?
Pergjigja e sakte eshte: 5777	*/

#include<stdio.h>
#include<math.h>

long p[10000]={3,5,7},i,j;
int k,n,flag;

int main(){
  for(i=9,n=2;;i+=2){
    j=sqrt(i);
    for(k=0;p[k]<=j;k++){
      if(i%p[k]==0) j=0;
      }
    if(j) p[++n]=i;
    else{
      for(k=flag=0;p[k]<i&&p[k];k++){
	j=sqrt((i-p[k])/2);
	if(j*j*2+p[k]==i){
	  flag=1;
	  break;
	  }
	}
      if(!flag) break;
      }
    }
  printf("\n%li\n",i);
  }

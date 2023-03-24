#include <stdio.h>

int isPrime(n){
  int i;
  if (n<=0)
    return 0;
  if (n==2)
    return 1;
  for (i=2;i<=n/2;i++)
    if(n%i==0)
      return 0;
  return 1;
}

int main(){
  int a,b,n,max,supermax,maxa,maxb;
  supermax=0;
  for (a=-999;a<1000;a++){
    for (b=-999;b<1000;b++){
      max=0;
      for (n=0;n<1000;n++){
        if(!isPrime((n*n)+(a*n)+b))
          break;
        max++;
      }
      if (max>supermax){
        supermax=max;
        maxa=a;
        maxb=b;
      }
    }
  }  
  printf("a = %d b = %d\n",maxa,maxb);      
return 0;
}

#include<stdio.h>
#include<math.h>
#define MAXN 32 
#define POW 5
int primes[MAXN];int nacina=0;
void f(int x,int k){ if(!x){nacina++;return;} if((k==1)){if(!(x%2)){nacina++;return;}else{return;}}
int i;f(x,k-1);
for(i=1;(x-i*primes[k-1])>=0;i++){
    f(x-i*primes[k-1],k-1);
}}
main(){primes[0]=2;
int n=3,m,i=1,j,high,low,mid,x;
while(i<MAXN){
        m=(int)(floor(sqrt(n))+0.1);if(m*m==n){goto label;}
        for(j=3;j<=m;j+=2){ if(!(n%j)){goto label;} } primes[i]=n;i++;
label:;n+=2;}
printf("Primes[] done\n");
for(n=10;n<100;n++){
high=MAXN-1;low=0;for(j=0;j<POW;j++){mid=(high+low)/2;if(n>primes[mid]){low=mid+1;}else{high=mid;}}
f(n,low-1);f(n-primes[low-1],low-1);
if(nacina>5000){break;}else{nacina=0;}}
printf("%d\n",n);}

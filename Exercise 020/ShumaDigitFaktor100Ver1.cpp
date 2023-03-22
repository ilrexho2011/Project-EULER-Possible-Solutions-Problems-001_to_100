#include <stdio.h>

#define MAX 500

int main(){
int vet[MAX]={0};
int i,x,y,v,f,sum;

vet[0]=1;
y=2;

while (y<101){
  v = 0;
  for (i=0;i<MAX;i++){
    x = vet[i]*y + v;
    v = 0;
    if (x > 9){
      f = x % 10;
      v = x / 10;      
    }
    else
      f = x;
    vet[i] = f;
  }
  y++;
}
sum=0;
for (i=MAX-1;i>=0;i--)
  sum=sum+vet[i];
printf("%d",sum);
return 0;
}

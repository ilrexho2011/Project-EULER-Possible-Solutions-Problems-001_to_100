#include <stdio.h>

int main(){
  int i,value,max,counter,max2,z;
  max=0;
  for (i=7;i<1000;i++){
    counter=0;
    value = 10%i;
    z=1000;
    while (value != 1 && z>0){
      value = value *10;
      value = value % i;
      counter++;
      z--;
    }
    if (counter>max && z>1){
      max=counter;
      max2=i;
    }
  }
  printf("%d\n",max2);
return 0;
}

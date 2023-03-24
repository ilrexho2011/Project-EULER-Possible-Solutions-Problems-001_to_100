#include <stdio.h>
 int main(){
     int i, a=1,j, sum=0;
     for(i=0;i<500;i++)//The spiral has 500 squares and the number one in the center
         for(j=0;j<4;j++){//For each square we sum 4 numbers (square cornes)
             a+=(2*(i+2)-2);//This is how the corner numbers increase
             sum+=a;
         }         
    printf("Answer: %d", sum+1);
    return 0;            
}

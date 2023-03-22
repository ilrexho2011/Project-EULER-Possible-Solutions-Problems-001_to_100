#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int amicable=0,num,sum1,sum2,i,j;

    for(num=1;num<10000;num++){
        sum1=1;
        for(i=2;i<=sqrt(num);i++){
            if(num%i==0){
                j=num/i;
                if(j==i){
                    sum1+=i;
                }
                else{
                    sum1+=i+j;
                }
            }
        }
        if(num==sum1){
            continue;
        }
        if(num>sum1){
        sum2=1;
        for(i=2;i<=sqrt(sum1);i++){
            if(sum1%i==0){
                j=sum1/i;
                if(j==i){
                    sum2+=i;
                }
                else{
                    sum2+=i+j;
                }
            }
        }
        if(num==sum2){
            amicable+=num+sum1;
        }
        }
    }
    printf("%d",amicable);

    return 0;
}

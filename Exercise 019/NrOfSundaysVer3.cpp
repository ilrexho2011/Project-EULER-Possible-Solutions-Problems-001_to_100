#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year=1900,mon=1,day=1,sun=0;

    while(year<=2000){
        for(mon=1;mon<=12;mon++){
            if(day==0&&year>=1901){
                sun++;
            }
            if(year==2000&&mon==12){
                break;
            }
            if(mon==1||mon==3||mon==5||mon==7||mon==8||mon==10||mon==12){
                day+=31;
                day=day%7;
            }
            else if(mon==4||mon==6||mon==9||mon==11){
                day+=30;
                day=day%7;
            }
            else if(mon==2){
                if(year%4==0&&year%100!=0){
                    day+=29;
                    day=day%7;
                }
                else if(year%4==0&&year%400==0){
                    day+=29;
                    day=day%7;
                }
                else{
                    day+=28;
                    day=day%7;
                }
            }

        }
        year++;
    }
    printf("%d",sun);
    return 0;
}

/*   Largest exponential

Problem 99
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.


Pergjigje:  709   */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
        int a,b;
        int c,d;
        int i=0,t;
        double max=0.0;
        double tmp;

        while(fscanf(stdin,"%d,%d",&a,&b) != EOF){
                i++;
                tmp = b*log(a);
                if(tmp > max){
                        c = a;
                        d = b;
                        max=tmp;
                        t = i;
                }
        }
        printf("%d: %d,%d %f\n",t,c,d,max);

        return 0;
}
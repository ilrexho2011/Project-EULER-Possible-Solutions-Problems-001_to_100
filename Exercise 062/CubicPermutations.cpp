

#include<stdio.h>
#include<string.h>
#include<math.h>
/* Cubic permutations

Problem 62 The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). 
In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
Find the smallest cube for which exactly five permutations of its digits are cube.

Pergjigje: 127035954683  */

char a[5360][11],count;

void main(){
  long double upper,lower,x,y=1,z;
  int i,j,n,digit;
  y/=3;
  for(digit=3;digit<13;digit++){
    lower=pow10(digit-1);
    x=lower=ceill(pow(lower,y));
    upper=pow10(digit)-1;
    upper=floorl(pow(upper,y));
    for(n=0;lower<=upper;n++,lower++){
      memset(a[n],'0',10);
      a[n][10]=0;
      z=lower*lower*lower;
      while(z){
	i=fmod(z,10);
	a[n][i]++;
	z/=10;
	z=floorl(z);
	}
      }
    for(i=0;i<n-4;i++){
      for(j=i+1,count=0;j<n;j++){
	if(!strcmp(a[i],a[j])){
	  if(++count==4){
	    printf("%.0Lf\n",(x+i)*(x+i)*(x+i));
	    if(count==4) break;
	    }
	  }
	}
      if(count==4) break;
      }
    if(count==4) break;
    }
  }
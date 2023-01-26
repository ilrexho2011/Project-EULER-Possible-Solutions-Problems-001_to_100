/*----------------------------------------------------------
	Shuma e numrave Prim poshte 10 eshte 2 + 3 + 5 + 7 = 17.
	Gjeni shumen e numrave Prim poshte vleres 2 milion.
	Pergjigja e sakte eshte 142913828922
	--------------------------------------------------------*/
# include <stdio.h>
# include <conio.h>
# include <iostream>
using namespace std;
long long arr[2000000],i,j;
long long shuma;
main (){
     for(i=1; i<2000000;i++)
     arr[i]=0;
      arr[0]=1;
    	arr[1]=1;
    	i=2;
     while (i*i<2000000){
           j=i;
           while(i*j<2000000){
           arr[i*j]=1;
           j++;
           }
           i++;
           while(arr[i]==1)
           i++;
           }
     shuma=0;
           for(i=1;i<=2000000;i++)
           if(arr[i]==0) shuma=shuma+i;
        
     cout<<shuma<<endl;
     getch();
           return 0;
           }

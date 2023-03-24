#include <iostream>   
 #include <cmath> 
 #define MAX 100
 using namespace std;

 int main(){
    int res=(MAX-1)*(MAX-1);
    for(int i=2;i<MAX;i++)
        for(int j=i*i;j<=MAX;j=j*i)
            res = res-int(MAX*(log(i)/log(j)))+1;
     cout<<res<<endl;
     return 0;
  }

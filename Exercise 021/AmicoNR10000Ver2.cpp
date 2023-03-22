#include <iostream>
using namespace std;
int main(){
     const int size=10001;
     int sumofdiv[size],i,j;
     for(i=1;i<size;i++) sumofdiv[i]=0;
     for(i=1;i<size;i++) for(j=2*i;j<size;j+=i) sumofdiv[j]+=i;
     int sumofamicable=0;
     for(i=1;i<size;i++) if(sumofdiv[i]<size && sumofdiv[sumofdiv[i]]==i && sumofdiv[i]!=i) sumofamicable+=i;
     cout<<sumofamicable;
}

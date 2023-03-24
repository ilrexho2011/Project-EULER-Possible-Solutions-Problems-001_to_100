#include<stdio.h>
int prime(int x){
	int a;
	if(x<2){
		return 0;
	}
	else if(x==2){
		return 1;
	}
	else{
		for(a=2;a<x;a++){
			if(x%a==0){
				return 0;
			}
			else if(a==x-1){
				return 1;
			}
		}
	}
}
int main(){
	int a,b,n,max=0,product=0;
	for(a=-999;a<1000;a++){
		for(b=-1000;b<1001;b++){
			for(n=0;n<1000;n++){
				if(prime(n*n+a*n+b)==1){
					continue;
				}
				else{
					break;
				}
			}
			if(n>max){
				max=n;
				product=a*b;
			}
		}
	}
	printf("%d",product);
	return 0;
}

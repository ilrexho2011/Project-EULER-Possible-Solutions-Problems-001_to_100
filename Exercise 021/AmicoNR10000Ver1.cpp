#include <stdio.h>
#define N 10000

int pdiv( int n ){
	int d = 1, i;
	for( i = 2; i*i < n; i++) d += (n%i == 0)*(i+n/i);
	return d+(i*i == n)*i;
}


int main(){
	int res = 0;
	for( int i = 2; i < N; i++ ) res += (pdiv(pdiv(i)) == i && pdiv(i) != i)*i;
	printf("%d\n", res);
	return 0;
}

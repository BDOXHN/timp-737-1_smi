#include <stdio.h>

int main(void){
	long n;
	long xi;
	long i = 1;
	double sum = 0;
	scanf("%li",&n);
	while(i <= n){
		scanf("%li", &xi);
		sum += ((i+1) % 2) * xi * xi * xi;
	i++;
	}
	printf("%g", sum);
}

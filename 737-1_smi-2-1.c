#include <stdio.h>

int main(void) {
	long n;
	long xi;
	long i = 1;
        double sum = 0;
	double result;
	scanf("%li", &n);
	while(i <= n){
		scanf("%li", &xi);
		sum += xi;
		i++;
	}
	result = sum/n;
	printf("%g", result);
}


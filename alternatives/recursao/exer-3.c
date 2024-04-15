#include <stdio.h>

unsigned int binario (unsigned int NUM) {
	//  Caso base
	if (NUM == 0)
		return 0;

	return ((binario (NUM / 2) * 10 ) + (NUM % 2));
}

int main () {
	unsigned int N;

	scanf("%d", &N);
	printf("Binario (%d): %d", N, binario(N));
	printf("\n");
	
	return 0;
}

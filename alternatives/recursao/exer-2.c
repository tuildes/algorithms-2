#include <stdio.h>

int soma_digitos (unsigned int NUM) {
	//  Caso base
	if (NUM == 0)
		return 0;

	return (soma_digitos(NUM / 10) + (NUM % 10));

}

int main () {
	unsigned int N;

	scanf("%d", &N);
	printf("Soma dos digitos de (%d): %d\n", N, soma_digitos(N));
	
	return 0;
}

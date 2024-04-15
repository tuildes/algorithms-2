#include <stdio.h>

unsigned int quantos_digitos_N (unsigned int NUM, unsigned int DIGITO) {
	//  Caso base
	if (NUM == 0)
		return 0;

	if (NUM % 10 == DIGITO)
		return (quantos_digitos_N((NUM/10), DIGITO) + 1);
	return quantos_digitos_N((NUM/10), DIGITO) + 0;
}

int main () {
	unsigned int N, DIGITO;

	printf("Digite o numero: ");
	scanf("%u", &N);
	printf("\nDigite o digito: ");
	scanf("%u", &DIGITO);
	printf("\n%u digitos %u em %u\n", quantos_digitos_N(N,DIGITO), DIGITO, N);
	
	return 0;
}

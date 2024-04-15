#include <stdio.h>

/* 
 * @params NUM - unsigned int - numero que vai ser somado
 * @return - unsigned int - retorna o somatorio de 1 a N
 */
int somatorio (unsigned int NUM) {
	// Caso base
	if (NUM == 0)
		return 0;
	
	return (somatorio(NUM-1) + NUM);	
}

int main () {
	unsigned int N, soma;

	scanf("%u", &N);
	soma = somatorio (N);

	printf("(%u): soma = %u\n", N, soma);

	return 0;
}

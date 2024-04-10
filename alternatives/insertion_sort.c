#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Troca dois index de posicao
void troca (int vetor[], int a, int b) {
	int temp = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = temp;
}

void insertion_sort (int v[], int a, int b) {
	// Caso base
	if (b <= a) 
		return;

	insertion_sort (v, a, b-1);

	for (int i = b-1; ((i >= a) && (v[i] > v[(i + 1)])); i--)
		troca (v, i, i+1);

	return;
}

void aleatorizar_vetor (int v[], int a, int b) {
	for (int i = a; i<=b; i++)
		v[i] = (rand() % 100);
}

void imprimir_vetor (int v[], int a, int b) {
	printf("Vetor: [");
	for (int i = a; i<=b; i++)
		printf("%d, ", v[i]);
	printf("]\n");
}

int main () {
	int vetor[10];

	srand(time(NULL));

	aleatorizar_vetor (vetor, 0, 9);

	imprimir_vetor (vetor, 0, 9);

	insertion_sort (vetor, 0, 9);

	imprimir_vetor (vetor, 0, 9);

	return 0;
}

#include <stdio.h>

// Considera hanoi de 3 hastes
void hanoi (int origin, int destiny, int aux, int size) {
	// Caso BASE
	if (size == 0)
		return;

	// Passar todos os menores para o 2
	hanoi (origin, aux, destiny, (size-1));
	// Resolver o atual para o 3
	printf ("Passou o disco %d, da haste %d para %d\n", size, origin, destiny);
	// Passar todos do 2 para o 3
	hanoi (aux, destiny, origin, (size-1));
};

int main () {
	int tam;

	scanf("%d", &tam);
	printf("Quanto maior o numero, maior o disco!!!\n");
	printf("Hanoi de %d discos com 3 hastes\n\n", tam);

	hanoi (1, 3, 2, tam);

}

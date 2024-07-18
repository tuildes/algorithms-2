#include <stdio.h>

void printSolution(unsigned int *s, const unsigned int size) {

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int j = 0; j < size; j++) {
			if (s[i] == j) printf("X ");
			else printf("_ ");
		}
		printf("\n");
	}
}

void resolverPosicao(unsigned int *solution, const unsigned int size, 
					 unsigned int line) {

	if (line == size) {
		printSolution(solution, size);
		printf("\n");
		return;
	}

	unsigned int possible;

	for (unsigned int i = 0; i < size; i++) {
		possible = 1;
		for (unsigned int j = 0; ((line != 0) && (j < line)); j++) {
			if ((solution[j] == i) || 
				(solution[j] == (i + line - j) || // Direita
				(solution[j] == (i - line + j) // Esquerda
				))) {

				possible = 0;
				break;
			}
		}

		if (possible) {
			solution[line] = i;
			resolverPosicao(solution, size, (line + 1));
		}
	}

	return;
}

int main () {

	unsigned int solution[15];

	resolverPosicao(solution, 15, 0);

	return 0;
}

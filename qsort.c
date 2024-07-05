#include <stdio.h>

// Faz uma troca dentro de um array
void switch_array (int *array, unsigned int a, unsigned int b) {
	const unsigned int temporary = array[a];
	array[a] = array[b];
	array[b] = temporary;
}

unsigned int partition (int *array, int start, int end) {

	// Variaveis
	int pivot = array[end];
	int middle = start;
	
	// Encontra o lugar do pivot
	for (int i = start; i < end; i++) {
		if (array[i] <= pivot) {
			switch_array(array, i, middle);
			middle++;
		}
	}

	// Coloca o pivot no seu lugar devido
	switch_array(array, middle, end);
	return middle;
}

void quick_sort (int *array, int start, int end) {
	
	// Caso base (nulo ou unitario)
	if (start >= end) return;

	// Particionamento do algoritmo
	int middle = partition (array, start, end);

	// Quick Sort para ambos os lados
	quick_sort(array, start, (middle - 1)); // Menores que array[middle]
	quick_sort(array, (middle + 1), end); // Maiores que array[middle]
}

// Imprimir o vetor no formato:
// Array (name): [ n1 n2 n3 ... nN ]
void print_array (int *orig, int lenght, const char *name) {

	printf("Array (%.*s): [ ", 4, name);

	for (int i = 0; i < lenght; i++)
		printf("%d ", orig[i]);

	printf("]\n");
}

int main () {
	
	// int subject[] = {72,11,11,12,18,100,(-5),(-23),0,1};
	int subject[] = {300, 200, 100, 300, 200, 100, 5, 10, 0, 0, 3000, 1, 2 , 234, 555};

	int lenght = (sizeof(subject) / sizeof(int));

	print_array(subject, lenght, "Origin");

	quick_sort(subject, 0, (lenght-1));

	print_array(subject, lenght, "QSort");

	return 0;
}

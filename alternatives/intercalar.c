#include <stdio.h>
#include <stdlib.h>

// Considera os mesmo tamanho aos dois
void merge (int arrA[], int arrB[], int tam, int res[]) {

	int j = 0;
	for (int i=0; i<tam; i++) {
		res[j] = arrA[i];
		res[j+1] = arrB[i];
		j+=2;
	};

	return;
}

void print_array (int array[], int tam) {

	for (int i=0; i<tam; i++) 
		printf("%d, ", array[i]);
	printf("\n");

	return;
}

void random_array (int arr[], int tam) {

	for (int i=0; i<tam; i++)
		arr[i] = (rand() % 100);
	
	return;
}

int main () {
	
	int arrayA[5], arrayB[5];
	int result[10];

	random_array (arrayA, 5);
	random_array (arrayB, 5);

	print_array (arrayA, 5);
	print_array (arrayB, 5);

	merge (arrayA, arrayB, 5, result);

	print_array (result, 10);

	return 0;
};

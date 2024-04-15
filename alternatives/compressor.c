#include <stdio.h>

int compressor (int a, int b, int c) {

	int comprimido;

	comprimido = a*1000000;
	comprimido += b*1000;
	comprimido += c;

	return comprimido;
}

void decompressor (int num, int vetor[]) {

	vetor[0] = num / 1000000;
	vetor[1] = (num / 1000) % 1000;
	vetor[2] = num % 1000;

};

int main () {
	int a, b, c;
	int vetor[3];
	int comprimido;

	printf ("Coloque os 3 numeros para comprimir (0 a 999)");
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);

	comprimido = compressor (a,b,c);

	printf ("Numeros a(%d), b(%d), c(%d): %d\n", a, b, c, comprimido);

	decompressor (comprimido, vetor);

	printf ("%d, %d, %d", vetor[0], vetor[1], vetor[2]);

	return 0;
};



//==========================================
//Author: Paulo R. Lisboa de Almeida
//Date:   7 Feb 2023
//==========================================

#include <stdio.h>

#define M 20 // Linhas
#define N 18 // Colunas
#define PAREDE 64
#define PASSAGEM 32
#define PASSOU 46
#define PASSOU_ERRADO 126

void imprimirLabirinto(int labirinto[][N]);
void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim);
int resolverLabirinto(int labirinto[][N], int linhaInicio, int colInicio, int linhaFim, int colFim);

int main(){
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;

	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);
	imprimirLabirinto(labirinto);

	if (resolverLabirinto(labirinto, linhaInicio, colInicio, linhaFim, colFim)) {
		printf("Possivel!\n");
	} else {
		printf("Impossivel!\n");
	}

	return 0;
}

void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim){
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for(int i=0; i < M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c",labirinto[i][j]);
		}
		printf("\n");
	}
}

int resolverLabirinto(int labirinto[][N], int X, int Y, int linhaFim, int colFim) {
	
	// Imprime o atual labirinto e seta como passado o seu local atual
	labirinto[X][Y] = PASSOU;
	imprimirLabirinto(labirinto);
	printf("\n");

	// Se resolveu
	if ((X == linhaFim) && (Y == colFim)) return 1;

	int possible = 0;

	// Baixo
	if ((X < M) && ((labirinto[(X + 1)][Y]) == PASSAGEM)) {
		possible = resolverLabirinto(labirinto, (X + 1), Y, linhaFim, colFim);
		if (possible) return 1;
	}
	
	// Direita
	if ((Y < N) && ((labirinto[X][(Y + 1)]) == PASSAGEM)) {
		possible = resolverLabirinto(labirinto, X, (Y + 1), linhaFim, colFim);
		if (possible) return 1;
	}
	
	// Esquerda
	if ((Y > 0) && ((labirinto[X][(Y - 1)]) == PASSAGEM)) {
		possible = resolverLabirinto(labirinto, X, (Y - 1), linhaFim, colFim);
		if (possible) return 1;
	}
	
	// Cima
	if ((X > 0) && ((labirinto[(X - 1)][Y]) == PASSAGEM)) {
		possible = resolverLabirinto(labirinto, (X - 1), Y, linhaFim, colFim);
		if (possible) return 1;
	}

	labirinto[X][Y] = PASSOU_ERRADO;
	return 0;
}

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_VALOR_ALEAT 10

/*
    Imprime o VETOR no formato:
    Vetor "nome":
    [ n1 n2 n3 n4 ... nN ]
*/
void imprimirVetor(int vetor[], size_t tam, char nome[]);

/*
    Aleatoriza todas as posições do vetor de [0..(tam-1)];
    Numeros aleatórioz: de 0 a MAX_VALOR_ALEAT
*/
void aleatorizarVetor(int vetor[], size_t tam);

/* Imprime os resultados de Index de Busca, comparações e tempo */
void resultados(size_t idxBusca, uint64_t numComp, double tempo);

#endif  // AUXILIAR_H_
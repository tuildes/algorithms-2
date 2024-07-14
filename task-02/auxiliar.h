#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>

#include "ordenacao.h"

#define MAX_INT_VALUE 536870912 // 2 elevado a 29
// #define MAX_INT_VALUE 100

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

/* 
    Imprime os resultados de comparações e tempo. 
    EXEMPLO: | ------------------------------- |
             | Resultado:			           |
             | ------------------------------- |
             | Tempo total:	             tempo |
             | Comparacoes:	           numComp |
             | ------------------------------- |

*/
void resultados(uint64_t numComp, double tempo);

/* 
    Verifica se esta ordenado
    Retorna 1 em caso de ERRO (não ordenado)
*/
unsigned short int testarOrdenacao(int vetor[], size_t tam);

#endif  // AUXILIAR_H_

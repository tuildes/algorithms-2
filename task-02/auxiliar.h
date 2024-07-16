#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>

#include "ordenacao.h"

#define MAX_INT_VALUE 536870912 // 2 elevado a 29, tamanho maximo possivel

/*
    Imprime o VETOR no formato:
    Vetor "nome":
    [ n1 n2 n3 n4 ... nN ]

    @param (int*) vetor - vetor que sera testado
    @param (size_t) tam - tamanho do vetor [0..(tam-1)]
    @param (char*) nome - nome do vetor que vai ser impresso
*/
void imprimirVetor(int vetor[/* tam */], size_t tam, const char nome[]);

/*
    Aleatoriza todas as posições do vetor de [0..(tam-1)];
    Numeros aleatórioz: de 0 a MAX_VALOR_ALEAT

    @param (int*) vetor - vetor que sera testado
    @param (size_t) tam - tamanho do vetor [0..(tam-1)]
*/
void aleatorizarVetor(int vetor[/* tam */], size_t tam);

/* 
    Imprime os resultados de comparações e tempo. 
    EXEMPLO: | ------------------------------- |
             | Resultado:			           |
             | ------------------------------- |
             | Tempo total:	             tempo |
             | Comparacoes:	           numComp |
             | ------------------------------- |

    @param (int*) vetor - vetor que sera testado
    @param (size_t) tam - tamanho do vetor [0..(tam-1)]
*/
void resultados(uint64_t numComp, double tempo);

/* 
    Verifica se esta ordenado o vetor
    Nao verifica possiveis perdas de dados

    @param (int*) vetor - vetor que sera testado
    @param (size_t) tam - tamanho do vetor [0..(tam-1)]
    @return (unsigned short int) - 0 para ORDENADO e 1 para NAO ORDENADO)
*/
unsigned short int testarOrdenacao(int vetor[], size_t tam);

#endif  // AUXILIAR_H_

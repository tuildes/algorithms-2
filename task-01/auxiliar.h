#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_VALOR_ALEAT 999999

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

/* 
    Verifica se esta ordenado
    Retorna 1 em caso de ERRO (não ordenado)
*/
unsigned short int testarOrdenacao(int vetor[], size_t tam);

/* 
    Verifica se a busca foi correta
    Retorna 1 em caso de ERRO (index não confere)
    Não verifica em caso de elemento não existente
*/
unsigned short int testarBusca(int vetor[], int valor, ssize_t index);

unsigned short int testarBuscaImpossivel(int vetor[], ssize_t index);

#endif  // AUXILIAR_H_
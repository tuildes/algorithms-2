#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define MAX_CHAR 50

// A função getNome deve colocar o seu nome no vetor
// Seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// Retorna o GRR do aluno: 00001234
uint32_t getGRR();

/*
    Merge Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente
    Esta função é um wrapper que chama intMergeSortRec()

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t mergeSort(int vetor[], size_t tam);

/*
    Merge Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t internoMergeSort(int vetor[], size_t inicio, size_t fim);

/*
    Merge (intercalar)
    Recebe um vetor com dois subvetores ordenados indexados:
        vetor_01 = [inicio..meio]
        vetor_02 = [(meio+1)..fim]
    E intercala ambos gerando um vetor ordenado index por inicio e fim

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) meio - indice do meio do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t merge(int vetor[], size_t inicio, size_t meio, size_t fim);

/*
    Trocar posições
    Dentro de um vetor, troca o valor indexado de dois índices

    @param (int*) vetor - vetor que terá a troca
    @param (size_t) pos1 - primeiro indice
    @param (size_t) pos2 - segundo indice
*/ 
void trocarPosicao(int vetor[], size_t pos1, size_t pos2);

uint64_t quickSort(int vetor[], size_t tam);

uint64_t heapSort(int vetor[], size_t tam);

// As funções que terminam em SR são "Sem Recursão"
uint64_t mergeSortSR(int vetor[], size_t tam);

uint64_t quickSortSR(int vetor[], size_t tam);

uint64_t heapSortSR(int vetor[], size_t tam);

#endif  // ORDENACAO_H_

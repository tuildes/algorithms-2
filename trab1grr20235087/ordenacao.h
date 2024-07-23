#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CHAR_NOME 50

// Função que coloca o nome do estudante em nome[]
// Tamanho máximo do nome eh MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// @returns {uint32_t} - GRR do estudante que fez o trabalho
uint32_t getGRR();

/* 
    Busca sequêncial (ingênua) recursiva
    Verifica qual o INDEX que o elemento procurado está

    @param {int*} vetor - vetor de origem que está ordenado
    @param {size_t} tam - tamanho do vetor a ser ordenado
    @param {int} valor - alvo da busca que será procurado no vetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {ssize_t} - indíce do elemento procurado ou -1 para não achado
*/
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes);

/* 
    Busca sequêncial (ingênua) iterativa
    Verifica qual o INDEX que o elemento procurado está

    @param {int*} vetor - vetor de origem que está ordenado
    @param {size_t} tam - tamanho do vetor a ser ordenado
    @param {int} valor - alvo da busca que será procurado no vetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {ssize_t} - indíce do elemento procurado ou -1 para não achado
*/
ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes);

/* 
    Busca binária recursiva
    Verifica qual o INDEX que o elemento procurado está
    Esta função é um wrapper que chama __buscaBinaria()

    @param {int*} vetor - vetor de origem que está ordenado
    @param {size_t} tam - tamanho do vetor a ser ordenado
    @param {int} valor - alvo da busca que será procurado no vetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {ssize_t} - indíce do elemento procurado ou -1 para não achado
*/
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes);
/* 
    Busca binária recursiva
    Verifica qual o INDEX que o elemento procurado deveria estar

    @param {int*} vetor - vetor de origem que está ordenado
    @param {int} inicio - indice inicial do subvetor a ser procurado
    @param {int} fim - indice final do subvetor a ser procurado
    @param {int} alvo - alvo da busca que será procurado no vetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {ssize_t} - possivel indice do elemento procurado no vetor
*/
ssize_t intBuscaBinariaRec(int vetor[], int inicio, int fim, 
                          int alvo, uint64_t* numComparacoes);

/* 
    Busca binária iterativa
    Verifica qual o INDEX que o elemento procurado está

    @param {int*} vetor - vetor de origem que está ordenado
    @param {size_t} tam - tamanho do vetor a ser ordenado
    @param {int} valor - alvo da busca que será procurado no vetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {ssize_t} - indíce do elemento procurado ou -1 para não achado
*/
ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes);

/*
    Insertion Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente
    Esta função é um wrapper que chama __insertionSortRec()

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t insertionSortRec(int vetor[], size_t tam);

/*
    Insertion Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) fim - indice final do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t __insertionSortRec(int vetor[], size_t fim);

/*
    Insertion Sort Iterativa
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t insertionSort(int vetor[], size_t tam);

/*
    Selection Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente
    Esta função é um wrapper que chama intSelectionSortRec()

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/            
uint64_t selectionSortRec(int vetor[], size_t tam);

/*
    Selection Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t intSelectionSortRec(int vetor[], size_t inicio, size_t fim);

/*
    Insertion Sort Iterativa
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t selectionSort(int vetor[], size_t tam);

/*
    Merge Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente
    Esta função é um wrapper que chama intMergeSortRec()

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t mergeSortRec(int vetor[], size_t tam);

/*
    Merge Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t intMergeSortRec(int vetor[], size_t inicio, size_t fim);

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

/*
    Mínimo de um vetor

    @param (int*) vetor - vetor que terá a troca
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @param (uint64_t*) numComparacoes - numero de comparações feitas
    @returns {int} - indice do menor elemento deste vetor
*/ 
int minimoVetor(int vetor[], size_t inicio, size_t fim, 
                uint64_t* numComparacoes);

#endif  // ORDENACAO_H_
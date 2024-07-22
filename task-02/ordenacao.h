#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "pilha.h"

#define MAX_CHAR 50
#define TRUE 1
#define FALSE 0

// A função getNome deve colocar o seu nome no vetor
// Seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// Retorna o GRR do aluno: 00001234
uint32_t getGRR();

/*
    Trocar posições
    Dentro de um vetor, troca o valor indexado de dois índices

    @param (int*) vetor - vetor que terá a troca
    @param (size_t) pos1 - primeiro indice
    @param (size_t) pos2 - segundo indice
*/ 
void trocarPosicao(int vetor[], size_t pos1, size_t pos2);

/*
    Merge Sort Recursivo
    Recebe um vetor e o ordena de forma não decrescente
    Esta função é um wrapper que chama internoMergeSort()

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t mergeSort(int vetor[], size_t tam);

/*
    NAO DEVE SER CHAMADA DE FORMA DIRETA

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
    E intercala ambos gerando um vetor ordenado indexado por inicio e fim

    @param (int*) vetor - vetor que vai ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) meio - indice do meio do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t merge(int vetor[], size_t inicio, size_t meio, size_t fim);

/*
    Particionar
    Recebe um vetor com inicio e fim, escolhe um pivo aleatorio dentro deste
    intervalo, e acha a posicao absoluta para a ordenacao deste pivo, gerando
    dois subvetores: esquerdo que contem os menores que o pivo e um direito
    que possue os maiores ou iguais ao pivo
    
    @param (int*) vetor - vetor que vai ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @param (uint64_t*) compar - total de comparacoes entre elementos do vetor
    @returns (size_t) - indice que o pivo ficou ao final da particao
*/
size_t particao (int *vetor, size_t inicio, size_t fim, uint64_t *compar);

/*
    NAO DEVE SER CHAMADA DE FORMA DIRETA

    Quick Sort Interno (recursivo)
    Recebe um vetor com indice de inicio e fim e faz a ordenacao deste vetor
    de forma nao decrescente utilizando o particionamento
    
    @param (int*) vetor - vetor que vai ser ordenado
    @param (size_t) inicio - indice inicial do subvetor
    @param (size_t) fim - indice final do subvetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t internoQuickSort(int *vetor, size_t inicio, size_t fim, 
                          uint64_t *compar);

/*
    Quick Sort envoltório (recursivo)
    Recebe um vetor com indice de inicio e fim e faz a ordenacao deste vetor
    de forma nao decrescente utilizando o particionamento

    @param (int*) vetor - vetor que vai ser ordenado
    @param (size_t) tam - tamanho do vetor a ser ordenado
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t quickSort(int vetor[], size_t tam);

/*
    Indice do filho esquerdo de um no
    
    @param (size_t) i - indice do no
    @returns (size_t) - indice do filho esquerdo
*/
size_t indiceFilhoEsquerdo (size_t i);

/*
    Indice do filho direito de um no
    
    @param (size_t) i - indice do no
    @returns (size_t) - indice do filho direito
*/
size_t indiceFilhoDireito (size_t i);

/*
    Max Heapify Recursivo
    Transforma um no em max heap, considera as sub arvores como max heaps

    @param (int*) vetor - vetor que vai virar max heap
    @param (size_t) inicio - indice do no que vai virar max heap
    @param (size_t) fim - indice da ultima folha dessa heap
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t maxHeapify(int vetor[], size_t inicio, size_t fim);

/*
    Construtor de Max Heap Recursivo
    Transforma um vetor em uma Max Heap

    @param (int*) vetor - vetor que vai virar max heap
    @param (size_t) inicio - indice inicial do vetor
    @param (size_t) fim - indice final do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t construirMaxHeap(int vetor[], size_t tam);

/*
    Heap Sort Recursivo
    Faz a ordenacao de um vetor utilizando max heaps de arvores binarias
    semi completas

    @param (int*) vetor - vetor que vai ser orednado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t heapSort(int vetor[], size_t tam);

/*
    Merge Sort Sem Recursao
    Recebe um vetor e o ordena de forma não decrescente
    Utiliza-se de pilhas para simular recursao

    @param (int*) vetor - tamanho que deseja ser ordenado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/ 
uint64_t mergeSortSR(int vetor[], size_t tam);

/*
    Quick Sort Sem Recursao
    Utiliza-se de pilhas para simular Recursao
    Recebe um vetor com indice de inicio e fim e faz a ordenacao deste vetor
    de forma nao decrescente utilizando o particionamento

    @param (int*) vetor - vetor que vai ser ordenado
    @param (size_t) tam - tamanho do vetor a ser ordenado
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t quickSortSR(int vetor[], size_t tam);

/*
    Max Heapify Sem Recursao
    Transforma um no em max heap, considera as sub arvores como max heaps

    @param (int*) vetor - vetor que vai virar max heap
    @param (size_t) inicio - indice do no que vai virar max heap
    @param (size_t) fim - indice da ultima folha dessa heap
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t maxHeapifySR(int vetor[], size_t inicio, size_t fim);

/*
    Construtor de Max Heap Sem Recursao
    Transforma um vetor em uma Max Heap

    @param (int*) vetor - vetor que vai virar max heap
    @param (size_t) inicio - indice inicial do vetor
    @param (size_t) fim - indice final do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t construirMaxHeapSR(int vetor[], size_t tam);

/*
    Heap Sort Sem Recursao
    Faz a ordenacao de um vetor utilizando max heaps de arvores binarias
    semi completas

    @param (int*) vetor - vetor que vai ser orednado
    @param (size_t) tam - tamanho do vetor
    @returns (uint64_t) - quantas comparações entre elementos foram feitas
*/
uint64_t heapSortSR(int vetor[], size_t tam);

#endif  // ORDENACAO_H_

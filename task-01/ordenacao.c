#include "ordenacao.h"

void getNome(char nome[]) {
    strncpy(nome, "Gustavo Benitez Frehse", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// Função que retorna o GRR do estudante
uint32_t getGRR() { return 20235087; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {

    for (int i=0; i < tam; i++) {
        *numComparacoes+=1;
        if (vetor[i] == valor)
            return i;
    }

    return -1;
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes) {
    // Caso base (n <= 0)
    if (tam <= 0)
        return -1;

    ssize_t resultadoRec = buscaSequencialRec(vetor, (tam-1), 
                                              valor, 
                                              numComparacoes);
    if (resultadoRec != -1)
        return resultadoRec;

    *numComparacoes+=1;
    if (vetor[(tam-1)] == valor)
        return (tam-1);
    return -1;
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
    *numComparacoes = 99;
    return -1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    *numComparacoes = 99;
    return -1;
}

uint64_t insertionSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

void imprimirVetor(int vetor[], size_t tam, char nome[]) {
    printf("\nVetor %s:\n[ ", nome);
    for (size_t i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("]\n");
}

void aleatorizarVetor(int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++)
        vetor[i] = (rand() % (MAX_VALOR_ALEAT + 1));
}
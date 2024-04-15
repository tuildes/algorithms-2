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

uint64_t mergeSortRec(int vetor[], size_t tam) {
    // Caso não seja necessário a ordenação
    // Esta exceção já proibe possíveis erros que o __mergeSort é propenso
    if (tam <= 1)
        return 0;

    // Chama realmente o mergeSort para a ordenação
    return __mergeSort(vetor, 0, (tam - 1));
}

uint64_t __mergeSort(int array[], size_t start, size_t end) {
    // Caso base da recursão
    if (start == end)
        return 0;

    size_t mid = floor(((end + start)/2));
    uint64_t comparisons = 0;
    comparisons += __mergeSort(array, start, mid);
    comparisons += __mergeSort(array, (mid+1), end);
    comparisons += merge(array, start, mid, end);
    return comparisons;
}

uint64_t merge(int vetor[], size_t start, size_t mid, size_t end) {
    int* aux;
    size_t i, j, cont;
    uint64_t comparacoes;

    // Aloca espaço para o vetor auxiliar
    aux = malloc((end-start+1) * sizeof(int));
    if (aux == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return -1;
    } 

    i=start;
    j=(mid+1);
    cont=0;
    comparacoes = 0;

    while((i <= mid) && (j <= end)) {
        if (vetor[i] < vetor[j]) {
            aux[cont] = vetor[i];
            i++;
        } else {
            aux[cont] = vetor[j];
            j++;
        }
        comparacoes++;
        cont++;
    }

    while(i <= mid) {
        aux[cont] = vetor[i];
        i++;
        cont++;
    }

    while(j <= end) {
        aux[cont] = vetor[j];
        j++;
        cont++;
    }

    // Colocar todo o vetor aux no vetor original
    for (cont=0; cont<=(end-start); cont++)
        vetor[(start+cont)] = aux[cont];

    free(aux);
    return comparacoes;
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
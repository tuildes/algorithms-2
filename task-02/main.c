#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

#define ATIVAR_IMPRESSAO 0

int main() {
    
    char nome[MAX_CHAR]; // Nome do estudante
    
    uint64_t numComp = 0; // Numero de comparacoes para avaliacao de custo
    ssize_t tamVetor; // Tamanho do vetor de ordenacao definido pelo usuario
    
    clock_t start, end; // Variaveis de calculo de tempo
    double total; // Tempo total de cada algoritmo
    
    srand(time(NULL)); // Define uma SEED aleatoria da sessao

    /* Define o tamanho do vetor com base na entrada do usuario */
    printf("Defina o tamanho do vetor:\t");
    if (scanf("%ld", &tamVetor) != 1) {
        printf("Falha fatal. Tamanho de vetor inváldo\n");
        return 1;
    }

    /* Define o tamanho do vetor e aloca seu espaco na memoria dinamica */
    int* vetor = (int*) malloc (tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    /* Identificacao do trabalho, pelo nome e GRR */
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    /* Merge Sort (Recursivo) */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nMerge Sort Recursivo:\n");
    
    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(numComp, total); // Imprime Resultados (tempo, comps)

    /* Quick Sort (Recursivo) */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nQuick Sort Recursivo:\n");
    
    start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(numComp, total); // Imprime Resultados (tempo, comps)

    /* Heap Sort (Recursivo) */
    /*
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nHeap Sort Recursivo:\n");
    
    start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(numComp, total); // Imprime Resultados (tempo, comps)
    */

    /* Quick Sort (Iterativo) */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nQuick Sort Iterativo:\n");
    
    start = clock();
    numComp = quickSortSR(vetor, tamVetor);
    end = clock();
    
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(numComp, total); // Imprime Resultados (tempo, comps)

    // numComp = quickSort(vetor, 3);
    // printf("NumComp: %d\n", numComp);
    // numComp = heapSort(vetor, 3);
    // printf("NumComp: %d\n", numComp);
    // numComp = mergeSortSR(vetor, 3);
    // printf("NumComp: %d\n", numComp);
    // numComp = quickSortSR(vetor, 3);
    // printf("NumComp: %d\n", numComp);
    // numComp = heapSortSR(vetor, 3);
    // printf("NumComp: %d\n", numComp);

    free(vetor); // Libera o espaco reservado do vetor

    return 0;
}

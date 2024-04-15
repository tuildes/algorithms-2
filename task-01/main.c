#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"

int main() {

    char nome[MAX_CHAR_NOME]; // Nome do estudante
    size_t idxBusca; // Index da busca
    uint64_t numComp; // Numero de comparacoes para avaliacao de custo
    ssize_t tamVetor; // Tamanho do vetor que pode ser definido pelo usuario
    clock_t start, end; // variáveis para calculo de tempo
    double total; // Tempo total decorrido em cada algoritmo

    // Define a seed do código
    srand(time(NULL));

    // Le o tamanho do vetor e aloca seu espaço na memória
    scanf("%ld", &tamVetor);
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    // Recebe o nome do estudante e imprime no inicio do programa
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    // Inicializa o vetor e imprime seu resultado
    aleatorizarVetor(vetor, tamVetor);
    // imprimirVetor(vetor, tamVetor, "inicial");

    start = clock();  // start recebe o "ciclo" corrente

    numComp = mergeSortRec(vetor, tamVetor);
    // numComp = insertionSortRec(vetor, 3);
    // idxBusca = buscaSequencial(vetor, tamVetor, 300, &numComp);
    // printf("\nIndex: %ld\n", idxBusca);

    end = clock();  // end recebe o "ciclo" corrente

    // Imprime o resultado final
    // imprimirVetor(vetor, tamVetor, "final");

    // o tempo total é a diferença dividia pelos ciclos por segundo
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);

    printf("Comparacoes: %ld\n", numComp);

    // numComp = selectionSortRec(vetor, 3);
    // numComp = selectionSort(vetor, 3);
    // idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
    // idxBusca = buscaBinaria(vetor, 3, 10, &numComp);

    // printf("\n%zd %lu", idxBusca, numComp);
    // printf("\n");

    // Liberação do espaço alocado pelo vetor
    free(vetor);

    return 0;
}

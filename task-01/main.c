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

    char nome[MAX_CHAR_NOME]; // Nome do estudante
    size_t idxBusca = -2; // Index da busca
    uint64_t numComp = 0; // Numero de comparacoes para avaliacao de custo
    ssize_t tamVetor; // Tamanho do vetor que pode ser definido pelo usuario
    clock_t start, end; // variáveis para calculo de tempo
    double total; // Tempo total decorrido em cada algoritmo

    srand(time(NULL)); // Define a SEED aleatória da execução

    /* Define o tamanho do vetor e aloca seu espaço na memória */
    printf("Defina o tamanho do vetor:\t");
    scanf("%ld", &tamVetor);
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    /* Identificação do trabalho, pelo nome e GRR */
    getNome(nome);
    printf("\nTrabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    /* Insertion Sort */
    aleatorizarVetor(vetor, tamVetor); // Preenche de forma aleatória todas as posições
    if (ATIVAR_IMPRESSAO) // Imprime o vetor inicialmente, caso esteja ativado a opcao
        imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nInsertion Sort Iterativo:\n");
    start = clock();
    numComp = insertionSort(vetor, tamVetor);
    end = clock();
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO) // Imprime o resultado final do vetor, caso esteja ativado a opcao
        imprimirVetor(vetor, tamVetor, "final");
    /* O tempo total em segundos, pela diferença divida por ciclos por segundo*/
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(idxBusca, numComp, total); // Imprime todos os resultados da aplicação

    /* Insertion Sort Recursivo */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nInsertion Sort Recursivo:\n");
    start = clock();
    numComp = insertionSortRec(vetor, tamVetor);
    end = clock();
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(idxBusca, numComp, total);

    /* Selection Sort */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nSelection Sort Iterativo:\n");
    start = clock();
    numComp = selectionSort(vetor, tamVetor);
    end = clock();
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(idxBusca, numComp, total);

    /* Selection Sort Recursivo */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nSelection Sort Recursivo:\n");
    start = clock();
    numComp = selectionSortRec(vetor, tamVetor);
    end = clock();
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(idxBusca, numComp, total);

    /* Merge Sort */
    aleatorizarVetor(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "inicial");
    printf("\nMerge Sort Recursivo:\n");
    start = clock();
    numComp = mergeSortRec(vetor, tamVetor);
    end = clock();
    testarOrdenacao(vetor, tamVetor);
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "final");
    total = ((double)end - start) / CLOCKS_PER_SEC;
    resultados(idxBusca, numComp, total);

    if (tamVetor > 0) {
        /* Busca Sequencial */
        printf("\nBusca Sequencial (ultimo elemento):\n");
        numComp = 0;
        start = clock();
        idxBusca = buscaSequencial(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        end = clock();
        testarBusca(vetor, vetor[(tamVetor-1)], idxBusca);
        total = ((double)end - start) / CLOCKS_PER_SEC;
        resultados(idxBusca, numComp, total);

        /* Busca Sequencial Recursiva */
        printf("\nBusca Sequencial Recursiva (ultimo elemento):\n");
        numComp = 0;
        start = clock();
        idxBusca = buscaSequencialRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        end = clock();
        testarBusca(vetor, vetor[(tamVetor-1)], idxBusca);
        total = ((double)end - start) / CLOCKS_PER_SEC;
        resultados(idxBusca, numComp, total);

        /* Busca Binaria */
        printf("\nBusca Binaria (ultimo elemento):\n");
        numComp = 0;
        start = clock();
        idxBusca = buscaBinaria(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        end = clock();
        testarBusca(vetor, vetor[(tamVetor-1)], idxBusca);
        total = ((double)end - start) / CLOCKS_PER_SEC;
        resultados(idxBusca, numComp, total);

        /* Busca Binaria Recursiva */
        printf("\nBusca Binaria Recursiva (ultimo elemento):\n");
        numComp = 0;
        start = clock();
        idxBusca = buscaBinariaRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        end = clock();
        testarBusca(vetor, vetor[(tamVetor-1)], idxBusca);
        total = ((double)end - start) / CLOCKS_PER_SEC;
        resultados(idxBusca, numComp, total);
    }

    free(vetor); // Liberação do espaço alocado pelo vetor
    return 0;
}

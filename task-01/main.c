#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

int main() {

    char nome[MAX_CHAR_NOME]; // Nome do estudante
    size_t idxBusca = -1; // Index da busca
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

    /* Inicializar o VETOR e preencher ele de forma aleatória */
    aleatorizarVetor(vetor, tamVetor);
    imprimirVetor(vetor, tamVetor, "inicial"); // Imprime o vetor inicialmente

    start = clock();  // start recebe o "ciclo" corrente

    numComp = mergeSortRec(vetor, tamVetor);
    // numComp = insertionSortRec(vetor, 3);

    // idxBusca = buscaSequencial(vetor, tamVetor, 5, &numComp);
    // idxBusca = buscaSequencialRec(vetor, tamVetor, 5, &numComp);
    // idxBusca = buscaBinaria(vetor, tamVetor, 5, &numComp);
    // idxBusca = buscaBinariaRec(vetor, tamVetor, 5, &numComp);

    end = clock();  // end recebe o "ciclo" corrente

    // imprimirVetor(vetor, tamVetor, "final"); // Imprime o resultado final do vetor

    /* O tempo total em segundos, pela diferença divida por ciclos por segundo*/
    total = ((double)end - start) / CLOCKS_PER_SEC;

    resultados(idxBusca, numComp, total);

    // Liberação do espaço alocado pelo vetor
    free(vetor);

    return 0;
}

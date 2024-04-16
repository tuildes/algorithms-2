#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"
#include "auxiliar.h"

#define ATIVAR_IMPRESSAO 0
#define ATIVAR_TESTES 1

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

    /* Inicializar o VETOR e preencher ele de forma aleatória */
    aleatorizarVetor(vetor, tamVetor);
    
    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "inicial"); // Imprime o vetor inicialmente

    mergeSortRec(vetor, tamVetor);

    start = clock();  // start recebe o "ciclo" corrente

    // numComp = mergeSortRec(vetor, tamVetor);

    // numComp = insertionSortRec(vetor, tamVetor);
    // numComp = insertionSort(vetor, tamVetor);

    // idxBusca = buscaSequencial(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
    // idxBusca = buscaSequencialRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
    // idxBusca = buscaBinaria(vetor, tamVetor, 2, &numComp); n funfa
    // idxBusca = buscaBinariaRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);

    end = clock();  // end recebe o "ciclo" corrente

    if (ATIVAR_IMPRESSAO)
        imprimirVetor(vetor, tamVetor, "final"); // Imprime o resultado final do vetor

    if (ATIVAR_TESTES) {
        /* TESTE DE ORDENACAO */
        printf("\nVerificação de ordenação:");
        if (testarOrdenacao(vetor, tamVetor)) {
            free(vetor);
            return 1;
        }

        /* TESTES DE BUSCA DO ELEMENTO DA ULTIMA POSICAO*/
        printf("\n[BUSCA SEQUENCIAL ITERATIVA] Teste de busca de ultima posicao:");
        idxBusca = buscaSequencial(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca)) {
            free(vetor);
            return 1;
        }

        printf("\n[BUSCA SEQUENCIAL RECURSIVA] Teste de busca de ultima posicao:");
        idxBusca = buscaSequencialRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca)) {
            free(vetor);
            return 1;
        }

        // printf("\n[BUSCA BINARIA ITERATIVA] Teste de busca de ultima posicao:");
        // idxBusca = buscaBinaria(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        // if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca)) {
        //     free(vetor);
        //     return 1;
        // }

        printf("\n[BUSCA BINARIA RECURSIVA] Teste de busca de ultima posicao:");
        idxBusca = buscaBinariaRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
        if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca)) {
            free(vetor);
            return 1;
        }

        /* TESTES DE BUSCA DE ELEMENTO INEXISTENTE */
        printf("\n[BUSCA SEQUENCIAL ITERATIVA] Teste de busca impossível:");
        idxBusca = buscaSequencial(vetor, tamVetor, -1, &numComp);
        if (testarBuscaImpossivel(vetor, idxBusca)) {
            free(vetor);
            return 1;
        }

        printf("\n[BUSCA SEQUENCIAL RECURSIVA] Teste de busca impossível:");
        idxBusca = buscaSequencialRec(vetor, tamVetor, -1, &numComp);
        if (testarBuscaImpossivel(vetor, idxBusca)) {
            free(vetor);
            return 1;
        }

        printf("\n[BUSCA BINARIA ITERATIVA] Teste de busca impossível:");
        idxBusca = buscaSequencial(vetor, tamVetor, -1, &numComp);
        if (testarBuscaImpossivel(vetor, idxBusca)) {
            free(vetor);
            return 1;
        }

        printf("\n[BUSCA BINARIA RECURSIVA] Teste de busca impossível:");
        idxBusca = buscaSequencial(vetor, tamVetor, -1, &numComp);
        if (testarBuscaImpossivel(vetor, idxBusca)) {
            free(vetor);
            return 1;
        }
    }

    // printf("\nTeste de busca impossível:");
    //  if (testarBusca(vetor, (-1), idxBusca)) {
    //     free(vetor);
    //     return 1;
    // }

    /* O tempo total em segundos, pela diferença divida por ciclos por segundo*/
    total = ((double)end - start) / CLOCKS_PER_SEC;

    resultados(idxBusca, numComp, total);

    // Liberação do espaço alocado pelo vetor
    free(vetor);

    return 0;
}

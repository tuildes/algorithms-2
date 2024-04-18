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
#define SELETOR_FUNCAO 5

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
    
    if (ATIVAR_IMPRESSAO) // Imprime o vetor inicialmente, caso esteja ativado a opcao
        imprimirVetor(vetor, tamVetor, "inicial");

    start = clock();  // start recebe o "ciclo" corrente

    if (SELETOR_FUNCAO == 6 || SELETOR_FUNCAO == 7 || SELETOR_FUNCAO == 8 || SELETOR_FUNCAO == 9)
        mergeSortRec(vetor, tamVetor); // Ordena caso seja escolhido as opcoes de busca

    switch(SELETOR_FUNCAO) {
        case 1:
            numComp = insertionSort(vetor, tamVetor);
            break;
        case 2:
            numComp = insertionSortRec(vetor, tamVetor);
            break;
        case 3:
            numComp = selectionSort(vetor, tamVetor);
            break;
        case 4:
            numComp = selectionSortRec(vetor, tamVetor);
            break;
        case 5:
            numComp = mergeSortRec(vetor, tamVetor);
            break;
        case 6:
            idxBusca = buscaSequencial(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
            break;
        case 7:
            idxBusca = buscaSequencialRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
            break;
        case 8:
            idxBusca = buscaBinaria(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
            break;
        case 9:    
            idxBusca = buscaBinariaRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
            break;
        default:
            printf("\nOpção inválida escolhida!\n");
            return 1;
    }

    end = clock();  // end recebe o "ciclo" corrente

    if (ATIVAR_IMPRESSAO) // Imprime o resultado final do vetor, caso esteja ativado a opcao
        imprimirVetor(vetor, tamVetor, "final");

    if (ATIVAR_TESTES) { // Realiza e imprime testes, caso esteja ativado a opcao
        if (realizarTestes(vetor, tamVetor)) {
            free(vetor);
            return 1;
        }
    }

    /* O tempo total em segundos, pela diferença divida por ciclos por segundo*/
    total = ((double)end - start) / CLOCKS_PER_SEC;
    
    resultados(idxBusca, numComp, total); // Imprime todos os resultados da aplicação

    free(vetor); // Liberação do espaço alocado pelo vetor

    return 0;
}

#include "auxiliar.h"

void imprimirVetor(int vetor[], size_t tam, char nome[]) {
    printf("\e[1m\nVetor %s:\n\e[m[ ", nome);
    for (size_t i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("]\n");
}

void aleatorizarVetor(int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++)
        vetor[i] = (rand() % (MAX_INT_VALUE));
}

void resultados(uint64_t numComp, double tempo) {
    /* Imprime os resultados */
    printf("\n");
    printf("\e[0;34m"); // Adiciona a coloração azulada
    printf("| ------------------------------- |\n");
    printf("| Resultado:\t\t\t  |\n");
    printf("| ------------------------------- |\n");
    printf("| Tempo total:\t %16f |\n", tempo);
    printf("| Comparacoes:\t %16ld |\n", numComp);
    printf("| ------------------------------- |\n");
    printf("\033[m"); // Remove a coloração amarela
}

unsigned short int testarOrdenacao(int vetor[], size_t tam) {

    if (tam <= 1) {
        printf("\e[0;32m\n[ORDENACAO] Vetor unitário ou vazio\n\033[m");
        return 0;
    }

    for (unsigned int i=0; i<=(tam-2); i++)
        if (vetor[i] > vetor[i+1]) {
            printf("\e[0;31m\n[NÃO PASSOU NO TESTE]\nO vetor não foi ordenado!\n\033[m");
            return 1;
        };
    printf("\e[0;32m\nVetor ordenado corretamente!\n\033[m");
    return 0;
}


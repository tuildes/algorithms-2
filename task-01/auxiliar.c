#include "auxiliar.h"

void imprimirVetor(int vetor[], size_t tam, char nome[]) {
    printf("\e[1m\nVetor %s:\n\e[m[ ", nome);
    for (size_t i = 0; i < tam; i++)
        printf("%d ", vetor[i]);
    printf("]\n");
}

void aleatorizarVetor(int vetor[], size_t tam) {
    for (size_t i = 0; i < tam; i++)
        vetor[i] = (rand() % (MAX_VALOR_ALEAT + 1));
}

void resultados(size_t idxBusca, uint64_t numComp, double tempo) {
    /* Imprime os resultados */
    printf("\n");
    printf("\033[33m"); // Adiciona a coloração amarela
    printf("| ------------------------------- |\n");
    printf("| Resultado:\t\t\t  |\n");
    printf("| ------------------------------- |\n");
    if (idxBusca != (-1))
        printf("| Index:\t %16ld |\n", idxBusca);
    else
        printf("| Index:  Não foi encontrado (-1) |\n");
    printf("| Tempo total:\t %16f |\n", tempo);
    printf("| Comparacoes:\t %16ld |\n", numComp);
    printf("| ------------------------------- |\n");
    printf("\033[m"); // Remove a coloração amarela
}
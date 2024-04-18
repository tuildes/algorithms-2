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
    printf("\e[0;34m"); // Adiciona a coloração azulada
    printf("| ------------------------------- |\n");
    printf("| Resultado:\t\t\t  |\n");
    printf("| ------------------------------- |\n");
    if (idxBusca == (-1))
        printf("| Index:  Não foi encontrado (%1ld) |\n", idxBusca);
    else if (idxBusca == -2)
         printf("| Não foi feito nenhuma busca\t  |\n");
    else
        printf("| Index:\t %16ld |\n", idxBusca);
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

unsigned short int testarBusca(int vetor[], int valor, ssize_t index) {
    // Caso de não realização de algum tipo de busca
    if (index == -2) {
        printf("\e[0;33m\nA busca de elemento não foi realizada\n\033[m");
        return 0;
    }
    // Caso de não achar o elemento na busca
    // Não é testado se o elemento realmente não existe no vetor
    if (index == -1) {
        printf("\e[0;31m\n[NÃO PASSOU NO TESTE]\nA busca não foi feita corretamente");
        printf("\e[0;31m\nO elemento não existe no vetor\n\033[m");
        return 1;
    }
    // Verifica se o elemento realmente é o mesmo buscado
    if (vetor[index] != valor) {
        printf("\e[0;31m\n[NÃO PASSOU NO TESTE]\nA busca não foi feita corretamente\n");
        printf("PROCURADO: %d em vetor[%ld]\n", valor, index);
        printf("ENCONTRADO: %d em vetor[%ld]\n\033[m", vetor[index], index);
        return 1;
    }
    printf("\e[0;32m\nBusca concluída com sucesso\n\033[m");
    return 0;
}

unsigned short int testarBuscaImpossivel(int vetor[], ssize_t index) {
    if (index != -1) {
        printf("\e[0;31m\n[NÃO PASSOU NO TESTE]\nFoi retornado uma posicao do vetor\n");
        return 1;
    }
    printf("\e[0;32m\nBusca concluída com sucesso\n\033[m");
    return 0;
}

unsigned short int realizarTestes(int vetor[], ssize_t tamVetor) {
    size_t idxBusca = -2;
    uint64_t numComp = 0; // Serve apenas como parametro obrigatorio

    /* TESTE DE ORDENACAO */
    printf("\nVerificação de ordenação:");
    if (testarOrdenacao(vetor, tamVetor))
        return 1;

    if (tamVetor == 0)
        return 0;

    /* TESTES DE BUSCA DO ELEMENTO DA ULTIMA POSICAO*/
    printf("\n[BUSCA SEQUENCIAL ITERATIVA] Teste de busca de ultima posicao:");
    idxBusca = buscaSequencial(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
    if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca))
        return 1;

    printf("\n[BUSCA SEQUENCIAL RECURSIVA] Teste de busca de ultima posicao:");
    idxBusca = buscaSequencialRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
    if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA ITERATIVA] Teste de busca de ultima posicao:");
    idxBusca = buscaBinaria(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);;
    if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA RECURSIVA] Teste de busca de ultima posicao:");
    idxBusca = buscaBinariaRec(vetor, tamVetor, vetor[(tamVetor-1)], &numComp);
    if (testarBusca(vetor, vetor[(tamVetor-1)], idxBusca))
        return 1;

    /* TESTES DE BUSCA DE ELEMENTO INEXISTENTE (-1) */
    printf("\n[BUSCA SEQUENCIAL ITERATIVA] Teste de busca impossível (-1):");
    idxBusca = buscaSequencial(vetor, tamVetor, -1, &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA SEQUENCIAL RECURSIVA] Teste de busca impossível (-1):");
    idxBusca = buscaSequencialRec(vetor, tamVetor, -1, &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA ITERATIVA] Teste de busca impossível (-1):");
    idxBusca = buscaBinaria(vetor, tamVetor, -1, &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA RECURSIVA] Teste de busca impossível (-1):");
    idxBusca = buscaBinariaRec(vetor, tamVetor, -1, &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    /* TESTES DE BUSCA DE ELEMENTO INEXISTENTE maior que todos */
    printf("\n[BUSCA SEQUENCIAL ITERATIVA] Teste de busca impossível (MAIOR QUE TUDO):");
    idxBusca = buscaSequencial(vetor, tamVetor, (vetor[tamVetor-1] + 1), &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA SEQUENCIAL RECURSIVA] Teste de busca impossível (MAIOR QUE TUDO):");
    idxBusca = buscaSequencialRec(vetor, tamVetor, (vetor[tamVetor-1] + 1), &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA ITERATIVA] Teste de busca impossível (MAIOR QUE TUDO):");
    idxBusca = buscaBinaria(vetor, tamVetor, (vetor[tamVetor-1] + 1), &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    printf("\n[BUSCA BINARIA RECURSIVA] Teste de busca impossível (MAIOR QUE TUDO):");
    idxBusca = buscaBinariaRec(vetor, tamVetor, (vetor[tamVetor-1] + 1), &numComp);
    if (testarBuscaImpossivel(vetor, idxBusca))
        return 1;

    return 0;
}
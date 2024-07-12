#include "ordenacao.h"

void getNome(char nome[]) {

    strncpy(nome, "Gustavo Benitez Frehse", MAX_CHAR);

    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20235087; }

uint64_t mergeSort(int vetor[/* tam */], size_t tam) {

    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1) return 0;

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return internoMergeSort(vetor, 0, (tam-1));
}

uint64_t internoMergeSort(int vetor[], size_t inicio, size_t fim) {

    // Caso base da recursão (vetor unitario)
    if (inicio == fim) return 0;

    // Define o meio do vetor (piso)
    size_t meio = ((fim + inicio)/2);
    uint64_t comparacoes = 0;

    // Ordenacação de ambos os lados, finalizando com a intercalacao
    comparacoes += internoMergeSort(vetor, inicio, meio); // Esquerdo
    comparacoes += internoMergeSort(vetor, (meio+1), fim); // Direito
    comparacoes += merge(vetor, inicio, meio, fim); // Intercala os valores

    return comparacoes;
}

uint64_t merge(int vetor[], size_t inicio, size_t meio, size_t fim) {

    // Variáveis locais
    int* aux; // Vetor temporario que recebe a ordenacao
    size_t i, j, // ìndíces
           cont; // Contador
    uint64_t comparacoes; // Total de comparações

    // Aloca espaço para o vetor auxiliar
    aux = malloc((fim-inicio+1) * sizeof(int));
    if (aux == NULL) { // Caso nao seja possivel alocar (ERRO)
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 0;
    } 

    // Inicializacao de variaveis
    i=inicio;
    j=(meio+1);
    cont=0;
    comparacoes = 0;

    // Intercala os dois subvetores até um deles acabar
    while((i <= meio) && (j <= fim)) {
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

    // Completa com o que falta do primeiro subvetor
    while(i <= meio) {
        aux[cont] = vetor[i];
        i++;
        cont++;
    }

    // Completa com o que falta do segundo subvetor
    while(j <= fim) {
        aux[cont] = vetor[j];
        j++;
        cont++;
    }

    // Copia tudo do vetor auxiliar no vetor de origem
    for (cont = 0; cont <= (fim-inicio); cont++)
        vetor[(inicio + cont)] = aux[cont];

    free(aux); // Libera o espaço armazenado do vetor auxiliar
    return comparacoes;
}

uint64_t quickSort(int vetor[], size_t tam) {

    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1) return 0; 

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return 0; // internoQuickSort(vetor, 0, (tam - 1));
}

/*

size_t particao (int *vetor, size_t inicio, size_t fim) {

    // Variaveis
    int pivo = vetor[fim];
    int meio = inicio;

    // Encontra o lugar do pivot
    for (size_t i = inicio; i < fim; i++) {
        if (vetor[i] <= pivo) {
            trocar_vetor(vetor, i, meio);
            meio++;
        }
    }

    // Coloca o pivot no seu lugar devido
    trocar_vetor(vetor, meio, fim);
    return meio;
}

void internoQuickSort(int *vetor, size_t inicio, size_t fim) {

        // Caso base (nulo ou unitario)
        if (inicio >= fim) return;

        // Particionamento do algoritmo
        int meio = particao (vetor, inicio, fim);

        // Quick Sort para ambos os lados
        quick_sort(vetor, inicio, (meio - 1)); // Menores que vetor[meio]
        quick_sort(vetor, (meio + 1), fim); // Maiores que vetor[meio]
}

*/

uint64_t heapSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

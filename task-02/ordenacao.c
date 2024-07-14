#include "ordenacao.h"

void getNome(char nome[]) {

    strncpy(nome, "Gustavo Benitez Frehse", MAX_CHAR);

    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20235087; }

void trocarPosicao(int vetor[], size_t pos1, size_t pos2) {
    const int auxiliar = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = auxiliar;
}

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

    // Ponteiro que representa o numreo de comparacoes
    uint64_t comparacoes = 0;

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return internoQuickSort(vetor, 0, (tam - 1), &comparacoes);
}

size_t particao (int *vetor, size_t inicio, size_t fim, uint64_t *compar) {

    // Variaveis
    int pivo;
    size_t posPivo;

    // Seleciona um aleatorio para ser o pivo
    trocarPosicao(vetor, 
                  fim, 
                  ((inicio + (rand() % (fim - inicio + 1)))));

    // Inicializar variaveis importantes do Quick Sort
    pivo = vetor[fim];
    posPivo = inicio;

    // Encontra o lugar do pivot
    for (size_t i = inicio; i < fim; i++) {
        *compar += 1;
        if (vetor[i] <= pivo) {
            trocarPosicao(vetor, i, posPivo);
            posPivo++;
        }
    }

    // Coloca o pivot no seu lugar devido
    trocarPosicao(vetor, posPivo, fim);
    return posPivo;
}

uint64_t internoQuickSort(int *vetor, ssize_t inicio, ssize_t fim, 
                          uint64_t *compar) {

    // Caso base (nulo ou unitario)
    if (inicio >= fim) return 0;

    // Particionamento do algoritmo
    size_t meio = particao (vetor, inicio, fim, compar);

    // Quick Sort para o lado dos menores (esquerdo)
    internoQuickSort(vetor, inicio, (meio - 1), compar);

    // Quick Sort para o lado dos maiores (direito)
    internoQuickSort(vetor, (meio + 1), fim, compar);
        
    return (*compar);
}

uint64_t heapSort(int vetor[], size_t tam) { return 0; }

uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {

    if (tam <= 1) return 0;

    // Ponteiro que representa o numreo de comparacoes
    uint64_t comparacoes = 0;

    // Indices de ordenacao
    size_t a, b;
    ssize_t posPivo; // Pode ser negativo (caso de posPivo-1)

    // Pilha de simulacao da recursao
    pilha p;
    inicializarPilha(&p, tam);

    // Inicializa a PILHA com os extremos
    empilhar(&p, 0);
    empilhar(&p, (tam - 1));

    while(!pilhaVazia(p)) {

        b = desempilhar(&p);
        a = desempilhar(&p);

        if (a < b) {
            // Particionamento do pivot (b)
            posPivo = particao(vetor, a, b, &comparacoes);

            // Lado esquerdo
            if (posPivo != 0) {
                empilhar(&p, a);
                empilhar(&p, (posPivo - 1));
            }
    
            // Lado direito
            empilhar(&p, (posPivo + 1));
            empilhar(&p, b);
        }
    }

    free(p.valor);
    return comparacoes;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

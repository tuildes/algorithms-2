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
    size_t meio = ((fim + inicio) >> 1);
    uint64_t comparacoes = 0;

    // Ordenacação de ambos os lados, finalizando com a intercalacao
    comparacoes += internoMergeSort(vetor, inicio, meio); // Esquerdo
    comparacoes += internoMergeSort(vetor, (meio + 1), fim); // Direito
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
        return (-1);
    } 

    // Inicializacao de variaveis
    i = inicio;
    j = (meio+1);
    cont = 0;
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

    // Encontra o lugar do pivo
    for (size_t i = inicio; i < fim; i++) {
        *compar += 1;
        if (vetor[i] <= pivo) {
            trocarPosicao(vetor, i, posPivo);
            posPivo++;
        }
    }

    // Coloca o pivo no seu lugar devido
    trocarPosicao(vetor, posPivo, fim);
    return posPivo;
}

uint64_t internoQuickSort(int *vetor, size_t inicio, size_t fim, 
                          uint64_t *compar) {

    // Caso base (nulo ou unitario)
    if (inicio >= fim) return 0;

    // Particionamento do algoritmo
    size_t posPivo = particao (vetor, inicio, fim, compar);

    // Quick Sort para o lado dos menores (esquerdo)
    if (posPivo != 0)
        internoQuickSort(vetor, inicio, (posPivo - 1), compar);

    // Quick Sort para o lado dos maiores (direito)
    internoQuickSort(vetor, (posPivo + 1), fim, compar);
        
    return (*compar);
}

size_t indiceFilhoEsquerdo (size_t i) { return ((i << 1) + 1);}
size_t indiceFilhoDireito (size_t i) { return ((i << 1) + 2); }

uint64_t maxHeapify(int vetor[], size_t inicio, size_t fim) {

    size_t esquerdo, direito, maior;

    esquerdo = indiceFilhoEsquerdo(inicio);
    direito = indiceFilhoDireito(inicio);

    if ((esquerdo <= fim) && (vetor[esquerdo] > vetor[inicio]))
        maior = esquerdo;
    else
        maior = inicio;

    if ((direito <= fim) && (vetor[direito] > vetor[maior]))
        maior = direito;

    // Se for necessario, faz a troca
    if (maior != inicio) {
        trocarPosicao(vetor, maior, inicio);
        return (2 + maxHeapify(vetor, maior, fim));
    }

    return 2;
}

uint64_t construirMaxHeap(int vetor[], size_t tam) {
    uint64_t comparacoes = 0;
    // Faz Max Heaps dos nos menores ate chegar na raiz
    for (int i = ((tam >> 1) - 1); i >= 0; i--)
        comparacoes += maxHeapify(vetor, i, (tam - 1));
    return comparacoes;
}

uint64_t heapSort(int vetor[], size_t tam) { 

    if (tam <= 1) return 0;

    // Constroi uma Max Heap completa
    uint64_t comparacoes = construirMaxHeap(vetor, tam);
    // Arruma as max heaps excluindo o elemento da raiz do maxHeapify
    for (size_t i = (tam - 1); i >= 1; i--) {
        trocarPosicao(vetor, 0, i);
        comparacoes += maxHeapify(vetor, 0, (i - 1));
    }

    return comparacoes;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {

    // Caso base da recursão (vetor unitario)
    if (tam <= 1) return 0;

    // Define as variaveis de funcao
    int a, b, meio;
    uint64_t comparacoes = 0;

    // Define a pilha de simulacao de recursao
    pilha p;
    if (inicializarPilha(&p, (tam << 2))) return (-1);

    // Inicializa a pilha com os indices EXTREMOS
    empilhar(&p, FALSE); // FALSO para Merge
    empilhar(&p, 0);
    empilhar(&p, (tam - 1));
    
    while(!pilhaVazia(p)) {
        
        b = desempilhar(&p);
        a = desempilhar(&p);

        if (a < b) {
            meio = ((b + a) >> 1);

            // Caso de TRUE para Merge
            if (desempilhar(&p)) {
                comparacoes += merge(vetor, a, meio, b);
                continue;
            }

            // Merge desta iteracao
            empilhar(&p, TRUE);
            empilhar(&p, a);
            empilhar(&p, b);

            // Lado direito
            empilhar(&p, FALSE);
            empilhar(&p, (meio + 1));
            empilhar(&p, b);

            // Lado esquerdo
            empilhar(&p, FALSE);
            empilhar(&p, a);
            empilhar(&p, meio);

        } else { 
            // Retirar o indice de MERGE
            desempilhar(&p); 
        }
    }

    destruirPilha(&p);

    return comparacoes;
}

uint64_t quickSortSR(int vetor[], size_t tam) {

    if (tam <= 1) return 0;

    // Ponteiro que representa o numero de comparacoes
    uint64_t comparacoes = 0;

    // Indices de ordenacao
    int a, b, posPivo;

    // Pilha de simulacao da recursao
    pilha p;
    if (inicializarPilha(&p, (tam << 1))) return (-1);

    // Inicializa a PILHA com os extremos
    empilhar(&p, 0);
    empilhar(&p, (tam - 1));

    while(!pilhaVazia(p)) {

        b = desempilhar(&p);
        a = desempilhar(&p);

        if (a < b) {
            // Particionamento do pivo (b)
            posPivo = particao(vetor, a, b, &comparacoes);

            // Lado esquerdo
            if (posPivo) {
                empilhar(&p, a);
                empilhar(&p, (posPivo - 1));
            }
    
            // Lado direito
            empilhar(&p, (posPivo + 1));
            empilhar(&p, b);
        }
    }

    destruirPilha(&p);
    return comparacoes;
}

uint64_t maxHeapifySR(int vetor[], size_t inicio, size_t fim) {

    size_t esquerdo, direito, maior;
    uint64_t comparacoes = 0;

    maior = (inicio + 1);

    // Continua fazendo o heapify ate ficar uma max heap
    while (maior != inicio) {

        esquerdo = indiceFilhoEsquerdo(inicio);
        direito = indiceFilhoDireito(inicio);

        // Define quem eh o maior entre os 3 nos
        if ((esquerdo <= fim) && (vetor[esquerdo] > vetor[inicio]))
            maior = esquerdo;
        else
            maior = inicio;
        if ((direito <= fim) && (vetor[direito] > vetor[maior]))
            maior = direito;

        comparacoes += 2; // Comparacoes por iteracao

        // Se for necessario faz a troca
        if (maior != inicio) {
            trocarPosicao(vetor, maior, inicio);
            inicio = maior;
            maior++; // Incrementa para ficar diferente
        }
    }
        
    return comparacoes;
}

uint64_t construirMaxHeapSR(int vetor[], size_t tam) {
    uint64_t comparacoes = 0;
    // Faz max Heaps dos nos menores ate chegar na raiz
    for (int i = ((tam >> 1) - 1); i >= 0; i--)
        comparacoes += maxHeapifySR(vetor, 0, (tam - 1));
    return comparacoes;
}

uint64_t heapSortSR(int vetor[], size_t tam) {

    if (tam <= 1) return 0;

    // Constroi uma max heap completa
    uint64_t comparacoes = construirMaxHeap(vetor, tam);

    // Arruma o max heap retirando a raiz do maxHeapify
    for (size_t i = (tam - 1); i >= 1; i--) {
        trocarPosicao(vetor, 0, i);
        comparacoes += maxHeapifySR(vetor, 0, (i - 1));
    }

    return comparacoes;
}

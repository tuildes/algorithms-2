#include "ordenacao.h"

void getNome(char nome[]) {
    strncpy(nome, "Gustavo Benitez Frehse", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// Função que retorna o GRR do estudante
uint32_t getGRR() { return 20235087; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {

    for (int i=0; i < tam; i++) {
        *numComparacoes+=1;
        if (vetor[i] == valor)
            return i;
    }

    return -1;
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes) {
    // Caso base (n <= 0)
    if (tam == 0)
        return -1;

    ssize_t resultadoRec = buscaSequencialRec(vetor, (tam-1), 
                                              valor, 
                                              numComparacoes);
    if (resultadoRec != -1)
        return resultadoRec;

    *numComparacoes+=1;
    if (vetor[(tam-1)] == valor)
        return (tam-1);
    return -1;
}

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
    
    ssize_t inicio = 0;
    ssize_t meio;
    ssize_t fim = (tam-1);

    while (inicio <= fim) {
        *numComparacoes+=1;
        meio = floor(((inicio + fim)/2));
        if (valor < vetor[meio])
            fim = (meio-1);
        else
            inicio = (meio+1);
    }

    inicio--;
    if ((inicio >= 0) && (inicio < tam) && (vetor[inicio] == valor))
        return inicio;
    return -1;
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    
    ssize_t result;

    if (tam == 0) 
        return -1;

    result = __buscaBinariaRec(vetor, 0, (tam-1), valor, numComparacoes);

    if ((result >= 0) && (result < tam) && (valor == vetor[result]))
        return result;
    return -1;
}

ssize_t __buscaBinariaRec(int array[], int start, int end, int target, uint64_t* numComparacoes) { 
    // Caso base da recursão (tamanho == 0)
    if (start > end)
        return (start-1);
    
    int mid = floor(((end + start)/2));
    *numComparacoes+=1;
    if (target < array[mid])
        return __buscaBinariaRec(array, start, (mid-1), target, numComparacoes);
    return __buscaBinariaRec(array, (mid+1), end, target, numComparacoes);
}

uint64_t insertionSort(int vetor[], size_t tam) {
    int temp;
    uint64_t comparacoes = 0;

    if (tam <= 0)
        return 0;

    for (unsigned int i=1; i<tam; i++) {
        for (unsigned int j=i; (j>=1); j--) {
            comparacoes++;

            if (vetor[j-1] <= vetor[j])
                break;

            temp = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = temp;
        }
    }

    return comparacoes;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    if (tam <= 0)
        return 0;
    return __insertionSortRec(vetor, (tam-1));
}

uint64_t __insertionSortRec(int array[], size_t end) {
	
	uint64_t comparations = 0;
	long int i;
    int temp;

	// Caso base
	if (end == 0)
		return 0;

	comparations += __insertionSortRec(array, (end-1));

	i = (end-1);
	while((i >= 0) && (array[i] > array[(i+1)])) {
		temp = array[i];
		array[i] = array[i+1];
		array[i+1] = temp;
		i--;
        comparations++;
	}

    return comparations;
}

int minimoVetor(int vetor[], size_t inicio, size_t fim, uint64_t* numComparacoes) {
    unsigned int menor = inicio;
    for (unsigned int i=(inicio+1); i<=fim; i++) {
        *numComparacoes+=1;
        if (vetor[i] < vetor[menor])
            menor = i;
    }
    return menor;
}

uint64_t selectionSort(int vetor[], size_t tam) {
    int temp, menor;
    uint64_t numComp = 0;

    // Casos de vetores previamente ordenado (unitario ou vazio)
    if (tam <= 1)
        return 0;

    for (unsigned int i=0; i<(tam-1); i++) {
        menor = minimoVetor(vetor, i, (tam-1), &numComp);
        temp = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = temp;
    }

    return numComp;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    if (tam <= 0)
        return 0;
    return __selectionSortRec(vetor, 0, (tam-1));
}

uint64_t __selectionSortRec (int vetor[], size_t start, size_t end) {
    int temp, menor;
    uint64_t numComp = 0;

    if (start == end)
        return 0;

    menor = minimoVetor(vetor, start, end, &numComp);

    temp = vetor[menor];
    vetor[menor] = vetor[start];
    vetor[start] = temp;

    return numComp + __selectionSortRec(vetor, (start+1), end);
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
    // Caso não seja necessário a ordenação
    // Esta exceção já proibe possíveis erros que o __mergeSortRec é propenso
    if (tam <= 1)
        return 0;

    // Chama realmente o mergeSort para a ordenação
    return __mergeSortRec(vetor, 0, (tam - 1));
}

uint64_t __mergeSortRec(int array[], size_t start, size_t end) {
    // Caso base da recursão
    if (start == end)
        return 0;

    size_t mid = floor(((end + start)/2));
    uint64_t comparisons = 0;
    comparisons += __mergeSortRec(array, start, mid);
    comparisons += __mergeSortRec(array, (mid+1), end);
    comparisons += merge(array, start, mid, end);
    return comparisons;
}

uint64_t merge(int vetor[], size_t start, size_t mid, size_t end) {
    int* aux;
    size_t i, j, cont;
    uint64_t comparacoes;

    // Aloca espaço para o vetor auxiliar
    aux = malloc((end-start+1) * sizeof(int));
    if (aux == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return -1;
    } 

    i=start;
    j=(mid+1);
    cont=0;
    comparacoes = 0;

    while((i <= mid) && (j <= end)) {
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

    while(i <= mid) {
        aux[cont] = vetor[i];
        i++;
        cont++;
    }

    while(j <= end) {
        aux[cont] = vetor[j];
        j++;
        cont++;
    }

    // Colocar todo o vetor aux no vetor original
    for (cont=0; cont<=(end-start); cont++)
        vetor[(start+cont)] = aux[cont];

    free(aux);
    return comparacoes;
}
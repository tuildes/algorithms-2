#include "ordenacao.h"

void getNome(char nome[]) {
    strncpy(nome, "Gustavo Benitez Frehse", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

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

    ssize_t resultado = buscaSequencialRec(vetor, (tam-1), 
                                              valor, 
                                              numComparacoes);
    if (resultado != -1)
        return resultado;

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
    
    ssize_t resultado;

    // Caso em que a busca binaria eh dispensável
    // Vetores nulos ou inexistentes
    if (tam == 0) 
        return -1;

    resultado = intBuscaBinariaRec(vetor, 0, (tam-1), valor, numComparacoes);
    if ((resultado >= 0) && (resultado < tam) && (valor == vetor[resultado]))
        return resultado; // Caso: Index RESULTADO seja realmente o valor buscado
    return -1; // Não encontrado
}

ssize_t intBuscaBinariaRec(int vetor[], int inicio, int fim, int alvo,
                          uint64_t* numComparacoes) { 
    // Caso base da recursão (tamanho == 0 & inversao de index)
    if (inicio > fim)
        return (inicio-1);
    
    int meio = floor(((fim + inicio)/2));
    *numComparacoes+=1;
    if (alvo < vetor[meio])
        return intBuscaBinariaRec(vetor, inicio, (meio-1), alvo, numComparacoes);
    return intBuscaBinariaRec(vetor, (meio+1), fim, alvo, numComparacoes);
}

uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t comparacoes = 0;
    ssize_t busca;

    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1)
        return 0;

    // Busca o local do elemento e aplica um shift de todos os elementos maiores
    for (unsigned int i=1; i<tam; i++) {
        busca = intBuscaBinariaRec(vetor, 0, (i-1), vetor[i], &comparacoes);
		for (unsigned int j=i; j>(busca+1); j--)
            trocarPosicao(vetor, j, (j-1));
    }

    return comparacoes;
}

uint64_t insertionSortRec(int vetor[], size_t tam) {
    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1)
        return 0;

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return __insertionSortRec(vetor, (tam-1));
}

uint64_t __insertionSortRec(int vetor[], size_t fim) {
	uint64_t comparacoes = 0;
    ssize_t busca;

	// Caso base (vetor unitário)
	if (fim == 0)
		return 0;

	comparacoes += __insertionSortRec(vetor, (fim-1));

    // Busca o local do elemento e aplica um shift de todos os elementos maiores
	busca = intBuscaBinariaRec(vetor, 0, (fim-1), vetor[fim], &comparacoes);
    for (unsigned int i=fim; i>(busca+1); i--)
        trocarPosicao(vetor, i, (i-1));

    return comparacoes;
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
    int menor;
    uint64_t numComp = 0;

    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1)
        return 0;

    // A cada iteracao, o menor elemento do subvetor
    // eh colocado no início do vetor
    for (unsigned int i=0; i<(tam-1); i++) {
        menor = minimoVetor(vetor, i, (tam-1), &numComp);
        trocarPosicao(vetor, menor, i);
    }

    return numComp;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1)
        return 0;

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return intSelectionSortRec(vetor, 0, (tam-1));
}

uint64_t intSelectionSortRec (int vetor[], size_t inicio, size_t fim) {
    int menor;
    uint64_t numComp = 0;

    // Caso base (vetor unitario)
    if (inicio == fim)
        return 0;

    // A cada iteracao, o menor elemento do subvetor
    // eh colocado no início do vetor
    menor = minimoVetor(vetor, inicio, fim, &numComp);
    trocarPosicao(vetor, menor, inicio);
    return numComp + intSelectionSortRec(vetor, (inicio+1), fim);
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
    // Caso em que a ordenacao eh dispensável
    // Vetores unitarios, vazios, ou inexistentes
    if (tam <= 1)
        return 0;

    // Algoritmo que realmente vai fazer a ordenacao recursivamente
    return intMergeSortRec(vetor, 0, (tam - 1));
}

uint64_t intMergeSortRec(int vetor[], size_t inicio, size_t fim) {
    // Caso base da recursão
    if (inicio == fim)
        return 0;

    size_t meio = floor(((fim + inicio)/2));
    uint64_t comparacoes = 0;
    comparacoes += intMergeSortRec(vetor, inicio, meio);
    comparacoes += intMergeSortRec(vetor, (meio+1), fim);
    comparacoes += merge(vetor, inicio, meio, fim);
    return comparacoes;
}

uint64_t merge(int vetor[], size_t inicio, size_t meio, size_t fim) {
    int* aux;
    size_t i, j, cont;
    uint64_t comparacoes;

    // Aloca espaço para o vetor auxiliar
    aux = malloc((fim-inicio+1) * sizeof(int));
    if (aux == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return -1;
    } 

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
    for (cont=0; cont<=(fim-inicio); cont++)
        vetor[(inicio+cont)] = aux[cont];

    free(aux); // Libera o espaço armazenado do vetor auxiliar
    return comparacoes;
}

void trocarPosicao(int vetor[], size_t pos1, size_t pos2) {
    int temp = vetor[pos1];
    vetor[pos1] = vetor[pos2];
    vetor[pos2] = temp;
}

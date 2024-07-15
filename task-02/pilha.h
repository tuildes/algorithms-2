#ifndef PILHA_H_
#define PILHA_H_

#include <stdlib.h>

// Pilha focada em indices
typedef struct {
    size_t altura;
    size_t topo;
    
    int *valor;
} pilha;

// Inicializa a pilha, com altura e memoria
unsigned int inicializarPilha(pilha *p, size_t tamanho); // Retorna 1 para ERRO

// Nao verifica se eh impossivel empilhar
void empilhar(pilha *p, int valor);

// Nao verifica se eh impossivel desempilhar
// Retorna o desempilhado (int)
int desempilhar(pilha *p);

/**
 * Verifica se a pilha esta vazia
 * Retorna 1 para VAZIA
 * Retorna 0 para NAO VAZIA
 * */
unsigned int pilhaVazia(pilha p);

#endif // PILHA_H_

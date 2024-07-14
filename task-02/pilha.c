#include "pilha.h"

unsigned int inicializarPilha(pilha *p, size_t tamanho) {
    
    p->valor = (size_t *) malloc (tamanho * sizeof(int));
    if (p->valor == NULL) return 1;

    p->altura = tamanho;
    p->topo = 0;

    return 0;
}

int empilhar(pilha *p, size_t valor) {

    p->valor[(p->topo)] = valor;
    p->topo++;

    return 0;
}

int desempilhar(pilha *p) {

    p->topo--;
    return p->valor[(p->topo)];
}

unsigned int pilhaVazia(pilha p) { return (p.topo == 0) ? 1 : 0; }

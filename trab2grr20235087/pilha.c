#include "pilha.h"

unsigned int inicializarPilha(pilha *p, size_t tamanho) {
    
    p->valor = (int *) malloc (tamanho * sizeof(int));
    if (p->valor == NULL) return 1;

    p->altura = tamanho;
    p->topo = 0;

    return 0;
}

void empilhar(pilha *p, int valor) {

    p->valor[(p->topo)] = valor;
    p->topo++;
}

int desempilhar(pilha *p) {

    p->topo--;
    return p->valor[(p->topo)];
}

unsigned int pilhaVazia(pilha p) { return (p.topo == 0) ? 1 : 0; }

void destruirPilha (pilha *p) {
    
    free(p->valor);
    p->topo = 0;
    p->altura = 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElemento {
    int elemento;
    struct tipoElemento *proximo;
} elementoPilha;

typedef struct tipoPilha {
    elementoPilha *topo;
} Pilha;

void init(Pilha *p) {
    p->topo = NULL;
}

int empty(Pilha *p) {
    if (p->topo == NULL) {
        return 1;
    }

    return 0;
}

int top(Pilha *p, int *elemento) {
    if (empty(p)) {
        return 0;
    }

    *elemento = p->topo->elemento;
    return 1;
}

int push(Pilha *p, int elemento) {
    elementoPilha *e = (elementoPilha *) malloc(sizeof(elementoPilha));
    if (e == NULL) {
        return 0;
    }

    e->elemento = elemento;
    e->proximo = p->topo;
    p->topo = e;
    return 1;
}

int pop(Pilha *p, int *elemento) {
    if (empty(p)) {
        return 0;
    }

    elementoPilha *e;
    e = p->topo;
    *elemento = e->elemento;
    p->topo = e->proximo;
    free(e);
    return 1;
}
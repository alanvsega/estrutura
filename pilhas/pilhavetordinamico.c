#include <stdio.h>
#include <stdlib.h>

struct tipoPilha {
    int topo;
    int *elementos;
    unsigned max;
};

typedef struct tipoPilha Pilha;

Pilha * init(unsigned max) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->max = max;
    p->topo = -1;
    p->elementos = (int *) malloc(p->max * sizeof(int));
    return p;
}

int full(Pilha *p) {
    if (p->topo == p->max -1) {
        return 1;
    }
    return 0;
}

int empty(Pilha *p) {
    if (p->topo == -1) {
        return 1;
    }
    return 0;
}

int push(Pilha *p, int elemento) {
    if (full(p)) {
        return 0;
    }
    p->topo++;
    p->elementos[p->topo] = elemento;
    return 1;
}

int pop(Pilha *p, int *elemento) {
    if (empty(p)) {
        return 0;
    }
    p->topo--;
    *elemento = p->elementos[p->topo+1];
    return 1;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct tipoPilha {
    int topo;
    int elementos[MAX];
};

typedef struct tipoPilha Pilha;

void init(Pilha *p) {
    p->topo == -1;
}

int full(Pilha *p) {
    if (p->topo == MAX -1) {
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
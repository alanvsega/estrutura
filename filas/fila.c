#include <stdio.h>
#include <stdlib.h>

typedef struct tipoElemento {
    int elemento;

    struct tipoElemento *prox;
} elementoFila;

typedef struct tipoFila {
    elementoFila *primeiro, *ultimo;
} Fila;

Fila *init() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

int empty(Fila *f) {
    if (f->primeiro == NULL) {
        return 1;
    }

    return 0;
}

int first(Fila *f, int *elemento) {
    if (empty(f)) {
        return 0;
    }

    *elemento = f->primeiro->elemento;

    return 1;
}

int enqueue(Fila *f, int elemento) {
    elementoFila *e = (elementoFila *) malloc(sizeof(elementoFila));
    
    if (e == NULL) {
        return 0;
    }

    if(empty(f)) {
        f->primeiro = elemento;
        f->ultimo = elemento;
    } else {
        f->ultimo->prox = e;
        e->elemento = elemento;
        e->prox = NULL;
        f->ultimo = e;
    }

    return 1;
}

int dequeue(Fila *f, int *elemento) {
    if (empty(f)) {
        return 0;
    }

    *elemento = f->primeiro->elemento;
    free(f->primeiro);
    f->primeiro = f->primeiro->prox;

    return 1;
}

int print(Fila *f) {
    elementoFila *e = (elementoFila *) malloc(sizeof(elementoFila));

    while(e != NULL) {
            
    }
}
#include <stdio.h>
#include <stdlib.h>

/* 5. Uma fila de prioridades é organizada de acordo com a prioridade (de 0 a 9) de um elemento. Desta forma, 
 * o registro de dados deve conter o valor do elemento e sua prioridade. Elementos com prioridade 0 devem 
 * estar no início da fila, seguidos dos elementos de prioridade 1, até que, por fim, estarão os elementos 
 * de prioridade 9. Desta forma, ao adicionar um novo elemento na fila, este deverá ser adicionado após o 
 * último elemento de mesma prioridade. Como a fila estará ordenada pela prioridade, a remoção não sofre 
 * alteração. Implemente uma fila de prioridades, com as estruturas necessárias e as seguintes operações 
 * init, empty, enqueue e dequeue.
 */

typedef struct tipoElementoPrioridade {
    int elemento;
    int prioridade;
    struct tipoFila *prox;
} elementoFilaPrioridade;

typedef struct tipoFilaPrioridade {
    struct tipoElementoPrioridade *primeiro, *ultimo;
} FilaPrioridade;


FilaPrioridade *init() {
    FilaPrioridade *f = (FilaPrioridade *) malloc(sizeof(FilaPrioridade));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

int empty(FilaPrioridade *f) {
    if (f->primeiro == NULL) {
        return 1;
    }

    return 0;
}

int first(FilaPrioridade *f, int *elemento, int *prioridade) {
    if (empty(f)) {
        return 0;
    }

    *elemento = f->primeiro->elemento;
    *prioridade = f->primeiro->prioridade;

    return 1;
}

int enqueue(FilaPrioridade *f, int elemento, int prioridade) {
    elementoFilaPrioridade *e = (elementoFilaPrioridade *) malloc(sizeof(elementoFilaPrioridade));
    
    if (e == NULL) {
        return 0;
    }

    if(empty(f)) {
        f->primeiro = e;
    } else {
        e = f->primeiro;
        while(e->prioridade <= prioridade) {
            if(e->prox == NULL) {
                f->ultimo->prox = e;
            } else {
                e = e->prox;
            }               
        }
        
    }

    
    f->ultimo = e;
    e->elemento = elemento;
    e->prox = NULL;

    return 1;
}

int dequeue(FilaPrioridade *f, int *elemento) {
    if (empty(f)) {
        return 0;
    }

    *elemento = f->primeiro->elemento;
    f->primeiro = f->primeiro->prox;
    return 1;
}
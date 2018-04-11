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
    struct tipoElementoPrioridade *prox;
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
    elementoFilaPrioridade *e2 = (elementoFilaPrioridade *) malloc(sizeof(elementoFilaPrioridade));
    
    if (e == NULL || e2 == NULL) {
        return 0;
    }

    if (prioridade < 0 || prioridade > 9){
        printf("Prioridade deve ser entre 0 e 9!\n");
        return 0;
    }

    if(empty(f)) {
        f->primeiro = e2;
    } else {
        e = f->primeiro;
        while(e->prioridade <= prioridade) {
            if(e->prox == NULL) {
                f->ultimo = e2;
                break;
            } else {
                if (e->prox->prioridade <= prioridade) {
                    e = e->prox;
                } else {
                    break;
                }                
            }               
        }
        
        e2->prox = e->prox;
        e->prox = e2;
    }

    e2->elemento = elemento;
    e2->prioridade = prioridade;

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

int print(FilaPrioridade *f) {
    if (empty(f)) {
        return 0;
    }

    elementoFilaPrioridade *e = (elementoFilaPrioridade *) malloc(sizeof(elementoFilaPrioridade));

    if (e == NULL) {
        return 0;
    }

    e = f->primeiro;
    printf("ELEMENTOS - ");

    while(e != NULL) {
        printf("%d", e->elemento);
        e = e->prox;
        if (e != NULL) {
            printf(", ");
        }
    }

    e = f->primeiro;
    printf("\nPRIORIDAD - ");

    while(e != NULL) {
        printf("%d", e->prioridade);
        e = e->prox;
        if (e != NULL) {
            printf(", ");
        }
    }
    printf("\n");

    return 1;
}

int main() {
    FilaPrioridade *fila1 = init();
    FilaPrioridade *fila2 = init();
    int i;
    
    enqueue(fila1, 1, 0);
    enqueue(fila1, 2, 0);
    enqueue(fila1, 3, 1);
    enqueue(fila1, 4, 1);
    enqueue(fila1, 2, 2);
    enqueue(fila1, 2, 2);
    enqueue(fila1, 5, 3);
    enqueue(fila1, 1, 3);
    enqueue(fila1, 3, 4);
    enqueue(fila1, 5, 4);
    enqueue(fila1, 7, 5);
    enqueue(fila1, 9, 5);

    printf("Fila 1:\n");
    print(fila1);

    enqueue(fila1, 9, 0);
    enqueue(fila1, 7, 4);
    enqueue(fila1, 6, 1);
    enqueue(fila1, 0, 7);
    enqueue(fila1, 9, 9);
    enqueue(fila1, 1, 8);

    printf("Fila 1 dps de inserir 9/0:\n");
    print(fila1);

    printf("Primeiro = %d/%d\n", fila1->primeiro->elemento, fila1->primeiro->prioridade);
    printf("Ultimo = %d/%d\n", fila1->ultimo->elemento, fila1->ultimo->prioridade);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Estruturas para Fila
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
        f->primeiro = e;
    } else {
        f->ultimo->prox = e;
    }

    f->ultimo = e;
    e->elemento = elemento;
    e->prox = NULL;

    return 1;
}

int dequeue(Fila *f, int *elemento) {
    if (empty(f)) {
        return 0;
    }

    *elemento = f->primeiro->elemento;
    f->primeiro = f->primeiro->prox;
    return 1;
}

// Exericios de Fila

// 1. Implementar a função print que imprime os elementos da fila
int print(Fila *f) {
    if (empty(f)) {
        return 0;
    }

    elementoFila *e = (elementoFila *) malloc(sizeof(elementoFila));
    e = f->primeiro;

    while(e != NULL) {
        printf("%d", e->elemento);
        e = e->prox;
        if (e != NULL) {
            printf(", ");
        }
    }

    printf("\n");
    return 1;
}

// 2. Dada uma fila, construir um procedimento que elimina dessa fila os n primeiros elementos.
// Prever a possibilidade da fila estar vazia e de não ter n elementos.
int contaElementos(Fila *f) {
    int qtd = 0;
    elementoFila *e = f->primeiro;
    while(e != NULL) {
        qtd++;
        e = e->prox;
    }

    return qtd;
}

int nDequeue(Fila *f, int n) {
    if (empty(f)) {
        return 0;
    }
    
    int *i = malloc(sizeof(int));
    elementoFila *e = (elementoFila *) malloc(sizeof(elementoFila));
    e = f->primeiro;

    // Verificando se a quantidade de elementos a se remover a maior do que a quantidade de elementos na fila.
    int qtd = contaElementos(f);

    // Se a quantidade de elementos for maior que o número a se deletar, programa para.
    if (n > qtd) {
        return 0;
    } else {
        while(n > 0) {
            dequeue(f, i);
            n--;
        }
    }

    return 1;
}

/* 3. Dadas duas filas: Q1 e Q2, contendo números inteiros ordenados. Construir um procedimento que
 * recebe as duas filas e faz a junção das duas gerando uma terceira. Essa terceira fila deverá ter
 * seus elementos ordenados. As duas filas dadas Q1 e Q2 ficarão vazias ao final do processo.
 */
int ordenaFila(Fila *f) {
    if (empty(f)) {
        return 0;
    }

    int qtd = contaElementos(f);
    elementoFila *e = (elementoFila*) malloc(sizeof(elementoFila));
    int i;

    e = f->primeiro;
    while (qtd > 0){
        if (e->elemento > e->prox->elemento) {
            i = e->elemento;
            e->elemento = e->prox->elemento;
            e->prox->elemento = i;
        }
        e = e->prox;

        if (e->prox == NULL) {
            e = f->primeiro;
            qtd--;
        }
    }

    return 1;
}

Fila* juntaFilas(Fila *q1, Fila *q2) {
    if (empty(q1) || empty(q2)) {
        exit(1);
    }

    Fila *q3 = (Fila*) malloc(sizeof(Fila));

    int *i = malloc(sizeof(int));

    while(!empty(q1)) {
        dequeue(q1, i);
        enqueue(q3, *i);
    }

    while(!empty(q2)) {
        dequeue(q2, i);
        enqueue(q3, *i);
    }

    ordenaFila(q3);

    return q3;
}


// 4. Construir uma função que receba duas filas Q1 e Q2, contendo números inteiros ordenados e constrói
// uma terceira fila, contendo os elementos da fila Q1 sem os elementos de interseção de Q1 com Q2.

/* 5. Uma fila de prioridades é organizada de acordo com a prioridade (de 0 a 9) de um elemento. Desta forma, 
 * o registro de dados deve conter o valor do elemento e sua prioridade. Elementos com prioridade 0 devem 
 * estar no início da fila, seguidos dos elementos de prioridade 1, até que, por fim, estarão os elementos 
 * de prioridade 9. Desta forma, ao adicionar um novo elemento na fila, este deverá ser adicionado após o 
 * último elemento de mesma prioridade. Como a fila estará ordenada pela prioridade, a remoção não sofre 
 * alteração. Implemente uma fila de prioridades, com as estruturas necessárias e as seguintes operações 
 * init, empty, enqueue e dequeue.
 */

// Função main para testes
int main() {
    Fila *fila1 = init();
    Fila *fila2 = init();
    int i;

    for(i=1; i<=10; i++) {
        enqueue(fila1, i);
    }

    for(i=11; i<=20; i++) {
        enqueue(fila2, i);
    }

    elementoFila *e = (elementoFila*) malloc(sizeof(elementoFila));

    printf("Fila 1:\n");
    print(fila1);

    printf("Fila 2:\n");
    print(fila2);

    printf("Fila 3:\n");
    print(juntaFilas(fila1, fila2));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
};

struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        raiz = (struct no*) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else {
        if ((rand() % 2) == 0) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);

        } else {
            if ((rand() % 2) == 0) {
                raiz -> esquerda = inserir(raiz -> esquerda, numero);
            } else {
                raiz -> direita = inserir(raiz -> direita, numero);
            }
        }
    }

    return raiz;
};

void navegarPreOrdem(struct no* raiz) {
    if (raiz != NULL) {
        printf("%d\t", raiz -> numero);
        navegarPreOrdem(raiz -> esquerda);
        navegarPreOrdem(raiz -> direita);
    ;}
};

void navegarEmOrdem(struct no* raiz) {
    if (raiz != NULL) {
        navegarEmOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero);
        navegarEmOrdem(raiz -> direita);
    ;}
};

void navegarPosOrdem(struct no* raiz) {
    if (raiz != NULL) {
        navegarPosOrdem(raiz -> esquerda);
        printf("%d\t", raiz -> numero); 
        navegarPosOrdem(raiz -> direita);
    }
;}
int main() {
    struct no *raiz = NULL;
    time_t t;
    srand((unsigned) time(&t));
    int i = 0;
    for (i = 0 ; i < 10 ; i++) {
        raiz = inserir(raiz, i);
    }

    printf("\n=============================== PRE-ORDEM =============================================\n");
    ;navegarPreOrdem(raiz);

    printf("\n=============================== EM-ORDEM =============================================\n");
    ;navegarEmOrdem(raiz);

    printf("\n=============================== POS-ORDEM =============================================\n");
    ;navegarPosOrdem(raiz);
;}


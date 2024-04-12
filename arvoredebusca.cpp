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
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> esquerda = NULL;
        raiz -> direita = NULL;
    } else {
        if (numero < raiz -> numero) {
            raiz -> esquerda = inserir(raiz -> esquerda, numero);

        } else if (numero > raiz -> numero) {
            raiz -> direita = inserir(raiz -> direita, numero);
        }
    }

    return raiz;

}

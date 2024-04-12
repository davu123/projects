#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct no {
    int numero;
    struct no *filho1;
    struct no *filho2;
    struct no *filho3;
    struct no *filho4;
    struct no *filho5;
};

struct no *inserir(struct no *raiz, int numero) {
    if (raiz == NULL) {
        raiz = (struct no *) malloc(sizeof(struct no));
        raiz -> numero = numero;
        raiz -> filho1 = NULL;
        raiz -> filho2 = NULL;
        raiz -> filho3 = NULL;
        raiz -> filho4 = NULL;
        raiz -> filho5 = NULL;
    } else {
        int sorteio = (rand() % 5);

        if (sorteio == 0) {
            raiz -> filho1 = inserir(raiz -> filho1, numero);
        } else if (sorteio == 1) {
            raiz -> filho2 = inserir(raiz -> filho2, numero);

        } else if (sorteio == 2) {
            raiz -> filho3 = inserir(raiz -> filho3, numero);

        } else if (sorteio == 3) {
            raiz -> filho4 = inserir(raiz -> filho4, numero);

        } else if (sorteio == 4) {
            raiz -> filho5 = inserir(raiz -> filho5, numero);

        }
    }    
}

void imprimir (struct no *raiz, char *endentacao) { 
    if (raiz != NULL) {
        printf("%s%d\n", endentacao, raiz -> numero);

        char *temp = (char *) malloc(1024 * sizeof(char));
        strcpy(temp, "---");
        strcat(temp, endentacao);
    
        imprimir(raiz -> filho1, temp);
        imprimir(raiz -> filho2, temp);
        imprimir(raiz -> filho3, temp);
        imprimir(raiz -> filho4, temp);
        imprimir(raiz -> filho5, temp);
    }
}

int main() {
    time_t t;
    srand((unsigned) time (&t));
    struct no *raiz = NULL;
    char *endentador = (char *) malloc(1024 * sizeof(char));
    imprimir(raiz, endentador);

    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 2);

    imprimir(raiz, endentador);

}

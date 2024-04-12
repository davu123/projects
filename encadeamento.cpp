#include <stdio.h>
#include <stdlib.h>

struct no {
    int numero;
    struct no* proximo;
};

struct no* cabeca = nullptr;

void inserir(int numero) {
    struct no* novoNo = (struct no*) malloc(sizeof(struct no));
    novoNo->numero = numero;
    novoNo->proximo = nullptr;

    if (cabeca == nullptr) {
        cabeca = novoNo;
    } else {
        struct no* ponteiro = cabeca;
        while (ponteiro->proximo != nullptr) {
            ponteiro = ponteiro->proximo;
        }
        ponteiro->proximo = novoNo;
    }
}

void imprimir() {
    printf("==============\n");
    struct no* ponteiro = cabeca;
    while (ponteiro != nullptr) {
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
}

void remover(int numero) {
    if (cabeca != nullptr) {
        if (cabeca->numero == numero) {
            struct no* ponteiroExcluir = cabeca;
            cabeca = cabeca->proximo;
            free(ponteiroExcluir);
        } else {
            struct no* ponteiroAnterior = cabeca;
            while ((ponteiroAnterior->proximo != nullptr) &&
                   (ponteiroAnterior->proximo->numero != numero)) {
                ponteiroAnterior = ponteiroAnterior->proximo;
            }
            if (ponteiroAnterior->proximo != nullptr) {
                struct no* ponteiroExcluir = ponteiroAnterior->proximo;
                ponteiroAnterior->proximo = ponteiroExcluir->proximo;
                free(ponteiroExcluir);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int opcao = 0;
    int numero = 0;

    while (opcao != 4) {
        printf("+====================+ \n ");
        printf("|         Menu de opcoes          | \n");
        printf("+=====================+ \n ");
        printf("|          1 - inserir            | \n");
        printf("|          2 - remover            | \n");
        printf("|          3 - imprimir           | \n");
        printf("|          4 - sair               | \n");
        printf("digite a opcao:     \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("digite o numero:     ");
                scanf("%d", &numero);
                inserir(numero);
                break;

            case 2:
                printf("digite o numero:      ");
                scanf("%d", &numero);
                remover(numero);
                break;

            case 3:
                imprimir();
                break;

            case 4:
                printf("saindo do programa. \n");
                break;

            default:
                printf("opcao invalida, tente novamente. \n");
                break;
        }
    }

    return 0;
}
 

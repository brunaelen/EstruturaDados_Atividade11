#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nome[50];
    struct Node* proximo;
};

struct Fila {
    struct Node *inicio, *fim;
};

void inicializarFila(struct Fila *fila) {
    fila->inicio = fila->fim = NULL;
}

void incluirNaFila(struct Fila *fila, char nome[]) {

    struct Node *novoNo = (struct Node*)malloc(sizeof(struct Node));
    strcpy(novoNo->nome, nome);
    novoNo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novoNo;
        return;
    }

    fila->fim->proximo = novoNo;
    fila->fim = novoNo;
}

void excluirDaFila(struct Fila *fila) {

    if (fila->inicio == NULL)
        return;

    struct Node *temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
}

void imprimirFila(struct Fila *fila) {
    struct Node* atual = fila->inicio;
    while (atual != NULL) {
        printf("%s -> ", atual->nome);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct Fila filaClientes;
    inicializarFila(&filaClientes);

    int quantidade;
    char nome[50];

    printf("Digite a quantidade de pessoas a serem atendidas na fila: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", nome);
        incluirNaFila(&filaClientes, nome);
    }

    printf("\nFila inicial:\n");
    imprimirFila(&filaClientes);

    excluirDaFila(&filaClientes);

    printf("\nFila após a remoção:\n");
    imprimirFila(&filaClientes);

    return 0;
}

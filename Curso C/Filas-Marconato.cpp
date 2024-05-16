#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct No {
    char prioridade;
    int numero;
    struct No *prox;
} No;

No *inicio = NULL;
No *fim = NULL;

void enfileirar(char prioridade, int numero) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    novoNo->prioridade = prioridade;
    novoNo->numero = numero;
    novoNo->prox = NULL;

    if (inicio == NULL) {
        inicio = novoNo;
        fim = novoNo;
    } else {
        fim->prox = novoNo;
        fim = novoNo;
    }
}

void desenfileirar() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    No *temp = inicio;
    inicio = inicio->prox;
    free(temp);
}

void exibirFila() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    No *atual = inicio;
    while (atual != NULL) {
        printf("%c%d ", atual->prioridade, atual->numero);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    char prioridade;
    int numero;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar pessoa na fila\n");
        printf("2 - Atender pessoa\n");
        printf("3 - Visualizar fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Informe a prioridade (N, I, D, G): ");
                scanf(" %c", &prioridade);
                printf("Informe o número da senha: ");
                scanf("%d", &numero);
                enfileirar(prioridade, numero);
                break;
            case '2':
                desenfileirar();
                break;
            case '3':
                exibirFila();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != '0');

    return 0;
}

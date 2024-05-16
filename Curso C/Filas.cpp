#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de um nó da fila
typedef struct Node {
    char* senha;
    struct Node* prox;
} Node;

// Definição da estrutura da fila
typedef struct {
    Node* inicio;
    Node* fim;
} Fila;

// Função para criar um novo nó
Node* criarNo(char* senha) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->senha = strdup(senha);
    novo->prox = NULL;
    return novo;
}

// Função para criar uma nova fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// Função para inserir um novo nó na fila de acordo com as prioridades
void inserirNaFila(Fila* fila, char* senha) {
    Node* novo = criarNo(senha);
    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        Node* atual = fila->inicio;
        Node* anterior = NULL;
        while (atual != NULL) {
            if (senha[0] == 'D' && atual->senha[0] != 'D') {
                // Insere deficiente antes de não deficientes
                break;
            } else if (senha[0] == 'I' && atual->senha[0] == 'N') {
                // Insere idoso antes de normal
                break;
            } else if (senha[0] == 'G' && (atual->senha[0] == 'N' || atual->senha[0] == 'I')) {
                // Insere gestante antes de normal ou idoso
                break;
            } else if (atual->prox == NULL) {
                // Insere no final se não houver mais nenhum nó
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
        if (anterior == NULL) {
            // Insere no início da fila
            novo->prox = fila->inicio;
            fila->inicio = novo;
        } else {
            // Insere após o nó anterior
            anterior->prox = novo;
            novo->prox = atual;
        }
        if (atual == NULL) {
            // Atualiza o fim da fila se chegou ao final
            fila->fim = novo;
        }
    }
}

// Função para remover e retornar o próximo da fila
char* proximoDaFila(Fila* fila) {
    if (fila->inicio == NULL) {
        return NULL;
    } else {
        Node* removido = fila->inicio;
        char* senha = removido->senha;
        fila->inicio = fila->inicio->prox;
        if (fila->inicio == NULL) {
            fila->fim = NULL;
        }
        free(removido);
        return senha;
    }
}

// Função para imprimir a fila
void imprimirFila(Fila* fila) {
    Node* atual = fila->inicio;
    while (atual != NULL) {
        printf("%s -> ", atual->senha);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    Fila* fila = criarFila();

    inserirNaFila(fila, "D3000");
    inserirNaFila(fila, "D3001");
    inserirNaFila(fila, "G4000");
    inserirNaFila(fila, "N1000");
    inserirNaFila(fila, "N1001");
    inserirNaFila(fila, "N1002");

    // Simulando atendimento
    while (fila->inicio != NULL) {
        char* senha = proximoDaFila(fila);
        printf("Atendendo: %s\n", senha);
        free(senha);
    }

    return 0;
}

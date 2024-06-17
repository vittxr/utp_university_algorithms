#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[30];
    int idade;
    struct pessoa *prox;
} Pessoa;

typedef struct ingresso {
    char filme[30];
    float valor;
    struct ingresso *prox;
} Ingresso;

Pessoa *enfileira(Pessoa *tras, char *nome, int idade) {
    // aloca um novo espaço na memória, com o tamanho exato da estrutura (struct) Pessoa
    Pessoa *novaPessoa = (Pessoa *)malloc(sizeof(Pessoa));
    if (!novaPessoa) return NULL;
    
    
    strcpy(novaPessoa->nome, nome);
    novaPessoa->idade = idade;
    novaPessoa->prox = NULL;
    
    if (tras) {
        tras->prox = novaPessoa;
    }
    return novaPessoa;
}

Pessoa *desenfileira(Pessoa *frente) {
    if (!frente) return NULL;
    
    Pessoa *proxima = frente->prox;
    free(frente);
    return proxima;
}

Ingresso *empilha(Ingresso *topo, char *nome, float valor) {
    Ingresso *novoIngresso = (Ingresso *)malloc(sizeof(Ingresso));
    if (!novoIngresso) return NULL;
    
    strcpy(novoIngresso->filme, nome);
    novoIngresso->valor = valor;
    novoIngresso->prox = topo;
    
    return novoIngresso;
}

Ingresso *desempilha(Ingresso *topo) {
    if (!topo) return NULL;
    
    Ingresso *proximo = topo->prox;
    free(topo);
    return proximo;
}

void imprimeFila(Pessoa *frente) {
    Pessoa *atual = frente;
    while (atual) {
        printf("Nome: %s, Idade: %d\n", atual->nome, atual->idade);
        atual = atual->prox;
    }
}

void imprimePilha(Ingresso *topo) {
    Ingresso *atual = topo;
    while (atual) {
        printf("Filme: %s, Valor: %.2f\n", atual->filme, atual->valor);
        atual = atual->prox;
    }
}

// generate .exe cmd: gcc main.c -o output & ./output (linux)
void main() {
    Pessoa *frente = NULL, *tras = NULL;
    Ingresso *topo = NULL;

    // Enfileira as pessoas
    tras = enfileira(tras, "Alice", 30);
    if (!frente) frente = tras;  // Set the front if it's the first person
    tras = enfileira(tras, "Bob", 25);
    tras = enfileira(tras, "Charlie", 20);

    printf("Fila de Pessoas:\n");
    imprimeFila(frente);

    // Desenfileira as pessoas
    frente = desenfileira(frente);
    printf("\nFila de Pessoas após desenfileirar:\n");
    imprimeFila(frente);

    // Colocar os tickets na pilhas
    topo = empilha(topo, "Inception", 12.50);
    topo = empilha(topo, "Matrix", 10.00);
    topo = empilha(topo, "Avatar", 15.00);

    printf("\nPilha de Ingressos:\n");
    imprimePilha(topo);

    // Remove os tickets da pilha
    topo = desempilha(topo);
    printf("\nPilha de Ingressos após desempilhar:\n");
    imprimePilha(topo);
}

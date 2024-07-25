#include "lista.h"

void criarLista(Lista *l){
    l = (Lista *) malloc(sizeof(Lista));
    l->No = NULL;
    return l;
}

void inserirInicio(Lista *l, int chave) {
    PONT novo = (PONT)malloc(sizeof(Elemento));
    novo->r.chave = chave;
    novo->ant = NULL;
    novo->prox = l->No;
    if (l->No != NULL) {
        l->No->ant = novo;
    }
    l->No = novo;
}

// Função para remover um elemento da lista
void remover(Lista *l, int chave) {
    PONT atual = l->No;
    while (atual != NULL) {
        if (atual->r.chave == chave) {
            if (atual->ant != NULL) {
                atual->ant->prox = atual->prox;
            } else {
                l->No = atual->prox;
            }
            if (atual->prox != NULL) {
                atual->prox->ant = atual->ant;
            }
            free(atual);
            return;
        }
        atual = atual->prox;
    }
}

// Função para imprimir a lista
void imprimir(Lista *l) {
    PONT atual = l->No;
    while (atual != NULL) {
        printf("%d ", atual->r.chave);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para buscar um elemento na lista
int busca(Lista *l, int chave) {
    PONT atual = l->No;
    while (atual != NULL) {
        if (atual->r.chave == chave) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

// Função para inserir um elemento no final da lista
void inserirFim(Lista *l, int chave) {
    PONT novo = (PONT)malloc(sizeof(Elemento));
    novo->r.chave = chave;
    novo->ant = NULL;
    novo->prox = NULL;
    if (l->No == NULL) {
        l->No = novo;
    } else {
        PONT atual = l->No;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }
}

// Função para remover o elemento do início da lista
void removerInicio(Lista *l) {
    if (l->No == NULL) {
        printf("Lista vazia\n");
        return;
    }
    PONT temp = l->No;
    l->No = l->No->prox;
    if (l->No!= NULL) {
        l->No->ant = NULL;
    }
    free(temp);
}

// Função para remover o elemento do final da lista
void removerFim(Lista *l) {
    if (l->No == NULL) {
        printf("Lista vazia\n");
        return;
    }
    PONT temp = l->No;
    if (temp->prox == NULL) {
        l->No = NULL;
    } else {
        while (temp->prox->prox!= NULL) {
            temp = temp->prox;
        }
        free(temp->prox);
        temp->prox = NULL;
    }
}
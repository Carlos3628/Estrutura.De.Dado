#include "lista.h"

Lista* criarLista() {
    Lista* list = (Lista*) malloc(sizeof(Lista));
    list->inicio = NULL;
    list->fim = NULL;
    return list;
}

void inserir(Lista* list, int valor) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = NULL;

    if (list->inicio == NULL) {
        list->inicio = novo_no;
        list->fim = novo_no;
    } else {
        if (valor < list->inicio->valor) {
            novo_no->proximo = list->inicio;
            list->inicio->anterior = novo_no;
            list->inicio = novo_no;
        } else if (valor > list->fim->valor) {
            novo_no->anterior = list->fim;
            list->fim->proximo = novo_no;
            list->fim = novo_no;
        } else {
            No* atual = list->inicio;
            while (atual->proximo != NULL && atual->proximo->valor < valor) {
                atual = atual->proximo;
            }
            novo_no->proximo = atual->proximo;
            novo_no->anterior = atual;
            if (atual->proximo != NULL) {
                atual->proximo->anterior = novo_no;
            }
            atual->proximo = novo_no;
        }
    }
}

void imprimir(Lista* list) {
    No* atual = list->inicio;
    while (atual != NULL) {
            printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void remover(Lista* list, int valor) {
    if (list->inicio == NULL) {
        return;
    }
    if (list->inicio->valor == valor) {
        No* temp = list->inicio;
        list->inicio = list->inicio->proximo;
        if (list->inicio != NULL) {
            list->inicio->anterior = NULL;
        } else {
            list->fim = NULL;
        }
        free(temp);
    } else if (list->fim->valor == valor) {
        No* temp = list->fim;
        list->fim = list->fim->anterior;
        if (list->fim != NULL) {
            list->fim->proximo = NULL;
        } else {
            list->inicio = NULL;
        }
        free(temp);
    } else {
        No* atual = list->inicio;
        while (atual->proximo != NULL && atual->proximo->valor != valor) {
            atual = atual->proximo;
        }
        if (atual->proximo != NULL) {
            No* temp = atual->proximo;
            atual->proximo = atual->proximo->proximo;
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual;
            }
            free(temp);
        }
    }
}

No* buscar(Lista* list, int valor) {
    No* atual = list->inicio;
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    return atual;
}
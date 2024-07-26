#include "arvore.h"

No* criar_no(int chave) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->chave = chave;
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
}

// Função para inserir um novo nó na árvore
No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criar_no(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } 
    else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

// Função para buscar um nó com uma determinada chave
No* busca_chave(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return busca_chave(raiz->esquerda, chave);
    } else {
        return busca_chave(raiz->direita, chave);
    }
}

// Função para remover um nó da árvore
No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }

    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }

    return raiz;
}

// Função para imprimir a árvore em pré-ordem
void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

// Função para imprimir a árvore em ordem
void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        em_ordem(raiz->direita);
    }
}

// Função para imprimir a árvore em pós-ordem
void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

// Função para encontrar o predecessor de um nó
No* predecessor(No* raiz, int chave) {
    No* atual = busca_chave(raiz, chave);
    if (atual == NULL) {
        return NULL;
    }

    if (atual->esquerda != NULL) {
        No* temp = atual->esquerda;
        while (temp->direita != NULL) {
            temp = temp->direita;
        }
        return temp;
    }

    No* pai = raiz;
    No* predecessor = NULL;
    while (pai != atual) {
        if (atual->chave < pai->chave) {
            predecessor = pai;
            pai = pai->esquerda;
        } else {
            pai = pai->direita;
        }
    }

    return predecessor;
}

No* sucessor(No* raiz, int chave) {
    No* atual = busca_chave(raiz, chave);
    if (atual == NULL) {
        return NULL;
    }

    if (atual->direita != NULL) {
        No* temp = atual->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        return temp;
    }

    No* pai = raiz;
    No* sucessor = NULL;
    while (pai != atual) {
        if (atual->chave > pai->chave) {
            sucessor = pai;
            pai = pai->direita;
        } else {
            pai = pai->esquerda;
        }
    }

    return sucessor;
}

// Função para encontrar o máximo da árvore
No* maximo(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    No* temp = raiz;
    while (temp->direita != NULL) {
        temp = temp->direita;
    }

    return temp;
}

// Função para encontrar o mínimo da árvore
No* minimo(No* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    No* temp = raiz;
    while (temp->esquerda != NULL) {
        temp = temp->esquerda;
    }

    return temp;
}
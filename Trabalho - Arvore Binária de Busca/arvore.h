#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int chave);
No* inserir(No* raiz, int chave);
No* busca_chave(No* raiz, int chave);
No* remover(No* raiz, int chave);
void pre_ordem(No* raiz);
void em_ordem(No* raiz);
void pos_ordem(No* raiz);
No* predecessor(No* raiz, int chave);
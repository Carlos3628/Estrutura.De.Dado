#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct Lista {
    No* inicio;
    No* fim;
} Lista;

Lista* criarLista();
void inserir(Lista* list, int valor);
void imprimir(Lista* list);
void remover(Lista* list, int valor);
No* buscar(Lista* list, int valor);
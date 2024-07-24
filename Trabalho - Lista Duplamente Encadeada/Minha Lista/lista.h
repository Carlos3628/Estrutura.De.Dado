#include <stdio.h>
#include <stdlib.h>

// Definição do tipo da chave
typedef int TipoChave;

// Definição do registro
typedef struct {
    TipoChave chave;
} Registro;

// Definição do elemento da lista
typedef struct AuxNo {
    struct AuxNo *ant;
    Registro r;
    struct AuxNo *prox;
} Elemento;

// Definição do ponteiro para o elemento
typedef Elemento *PONT;

// Definição da lista
typedef struct {
    PONT No;
} Lista;

void criarLista(Lista *l);
void inserirInicio(Lista *l, int chave);
void remover(Lista *l, int chave);
void imprimir(Lista *l);
void inserirFim(Lista *l, int chave);
void removerInicio(Lista *l);
void removerFim(Lista *l);
int busca(Lista *l, int chave);
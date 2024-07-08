#include <stdio.h>
#include <stdlib.h>

#define max 30
#define erro -1

typedef int TipoChave;

typedef struct {
    TipoChave chave;
} Registro;

typedef struct {
    Registro V[max];
    int N;
} Lista;

void IniciarLista(Lista *L);
int RetornarElementos(Lista L);
int Busca(Lista *L,TipoChave *ch);
int InsereFinal(Lista *L, Registro *R);
int InsereComeco(Lista *L, Registro *R);
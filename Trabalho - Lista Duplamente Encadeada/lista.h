#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;
typedef struct{
    TipoChave chave;
}Registro;

typedef struct AuxNo{
    struct AuxNo *ant;
    Registro r;
    struct AuxNo *prox;
}Elemento;

typedef Elemento *PONT;
typedef struct{
    PONT No;
}Lista;

void IniciarLista(Lista *L);
int RetornarTamanho(Lista *L);
void ImprimirList(Lista *L);
void InserirInicio(Lista *L, int ch);
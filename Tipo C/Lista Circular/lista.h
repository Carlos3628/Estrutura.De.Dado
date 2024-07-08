#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TipoChave;
typedef struct{
    TipoChave chave;
}Registro;

typedef struct AuxElemento{
    Registro r;
    struct AuxElemento *proximo;
}Elemento;

typedef Elemento *Pont;
typedef struct{
    Pont No;
}Lista;

void IniciarLista(Lista *L);
void Imprimir(Lista *L);
int Tamanho(Lista *L);
Pont Busca(Lista *L, TipoChave chave);
Pont BuscaOrdenada(Lista *L, TipoChave chave);
Pont BuscaSequencial(Lista *L, TipoChave chave, Pont *anterior);
bool InserirElemento(Lista *L, Registro r);
bool ExcluirElemento(Lista *L, TipoChave chave);
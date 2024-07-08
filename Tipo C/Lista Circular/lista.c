#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

void IniciarLista(Lista *L){
    L->No=(Pont)malloc(sizeof(Elemento));
    L->No->proximo=L->No;
}

int Tamanho(Lista *L){
    Pont aux=L->No->proximo;
    int tam = 0;
    while(aux!=L->No){
        tam++;
        aux = aux->proximo;
    }
    return tam;
}

void Imprimir(Lista *L){
    Pont aux=L->No->proximo;
    while(aux!=L->No){
        printf("%d", aux->r.chave);
        aux=aux->proximo;
    }
    printf("\n\n");
}

Pont Busca(Lista *L, TipoChave chave){
    Pont posicao=L->No->proximo;
    L->No->r.chave=chave;
    while(posicao->r.chave!=chave){
        posicao=posicao->proximo;
    }
    if(posicao!=L->No){
        return posicao;
    }
    return NULL;
}

Pont BuscaOrdenada(Lista *L, TipoChave chave){
    Pont posicao=L->No->proximo;
    L->No->r.chave=chave;
    while(posicao->r.chave<chave){
        posicao=posicao->proximo;
    }
    if((posicao!=L->No) && (posicao->r.chave==chave)){
        return posicao;
    }
    return NULL;
}

Pont BuscaSequencial(Lista *L, TipoChave chave, Pont *anterior){
    *anterior=L->No;
    Pont atual=L->No->proximo;
    L->No->r.chave=chave;
    while(atual->r.chave<chave){
        *anterior=atual;
        atual=atual->proximo;
    }
    if((atual!=L->No) && (atual->r.chave==chave)){
        return atual;
    }
    return NULL;
}

bool InserirElemento(Lista *L, Registro r){
    Pont anterior, i;
    i=BuscaSequencial(L,r.chave,&anterior);
    if(i!=NULL){
        return false;
    }
    i=(Pont) malloc(sizeof(Elemento));
    i->r=r;
    i->proximo=anterior->proximo;
    anterior->proximo=i;
    return true;
}

bool ExcluirElemento(Lista *L, TipoChave chave){
    Pont anterior, i;
    i=BuscaSequencial(L,chave,&anterior);
    if(i==NULL){
        return false;
    }
    anterior->proximo=i->proximo;
    free(i);
    return true;
}
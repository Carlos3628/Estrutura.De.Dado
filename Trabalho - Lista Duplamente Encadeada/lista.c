#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void IniciarLista(Lista *L){
    L->No = (PONT) malloc (sizeof(Elemento));
    L->No->prox = NULL;
    L->No->ant = NULL;
}

int RetornarTamanho(Lista *L){
    PONT aux = L->No->prox;
    int tam = 0;
    while(aux!=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void ImprimirLista(Lista *L){
    PONT aux = L->No->prox;
    while(aux!=NULL){
        printf("\n %d", aux->r.chave);
        aux = aux->prox;
    }
}

void InserirInicio(Lista *L, int ch){
    PONT N, aux = L->No->prox;
    N = (PONT) malloc (sizeof(Elemento));
    N->No->r.chave = ch;
    N->No->prox = NULL;
    N->No->ant = L->No;
    if(aux==NULL){
        L->No->prox = N->No;
    }
    else{
        N->No->prox = L->No->prox;
        L->No->prox = N->No;
        aux->ant = N->No;
    }
}
#include <stdio.h>
#include "Lista.h"

int InsereFinal(Lista *L, Registro *R){
    if(L->N==max){
        return erro;
    }
    else{
        L->V[L->N]=*R;
        L->N++;
        return 0;
    }
}

int InsereComeco(Lista *L, Registro *R){
    if(L->N==0){
        L->V[L->N]=*R;
        L->N++;
        return 0;
    }
    else{
        if(L->N==max){
            return erro;
        }
        else{
            for(int j=L->N;j>=0;j--){
                L->V[j]=L->V[j-1];
            }
            L->V[L->N]=*R;
            return 0;
        }
    }
}
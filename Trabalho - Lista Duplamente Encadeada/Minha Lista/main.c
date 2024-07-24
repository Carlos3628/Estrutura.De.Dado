#include "lista.c"

int main() {
    Lista *l;
    criarLista(l);

    // Teste de inserção no início
    inserirInicio(l, 1);
    inserirInicio(l, 2);
    inserirInicio(l, 3);
    imprimir(l); // imprime: 3 2 1

    // Teste de inserção no final
    inserirFim(l, 4);
    inserirFim(l, 5);
    imprimir(l); // imprime: 3 2 1 4 5

    // Teste de busca
    int encontrado;
    encontrado = busca(l, 2);
    if (encontrado != 1) {
        printf("Encontrado");
    } else {
        printf("Não encontrado");
    }

    // Teste de remoção do início
    removerInicio(l);
    imprimir(l); // imprime: 2 1 4 5
    removerInicio(l);
    imprimir(l); // imprime: 1 4 5

    // Teste de remoção do final
    removerFim(l);
    imprimir(l); // imprime: 1 4
    removerFim(l);
    imprimir(l); // imprime: 1

    // Teste de remoção do único elemento
    removerInicio(l);
    imprimir(l); // imprime: (lista vazia)

    return 0;
}
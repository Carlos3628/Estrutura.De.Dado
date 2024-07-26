#include "arvore.c"

int main() {
    No* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 8);

    // Imprimindo a árvore em ordem
    printf("Árvore em ordem: ");
    em_ordem(raiz);
    printf("\n");

    // Buscando um valor na árvore
    No* resultado = busca_chave(raiz, 4);
    if (resultado != NULL) {
        printf("Valor encontrado: %d\n", resultado->chave);
    } else {
        printf("Valor não encontrado\n");
    }

    // Removendo um valor da árvore
    raiz = remover(raiz, 4);

    // Imprimindo a árvore em ordem após a remoção
    printf("Árvore em ordem após a remoção: ");
    em_ordem(raiz);
    printf("\n");

    // Encontrando o predecessor de um valor
    No* predecessor_resultado = predecessor(raiz, 6);
    if (predecessor_resultado != NULL) {
        printf("Predecessor de 6: %d\n", predecessor_resultado->chave);
    } else {
        printf("Predecessor não encontrado\n");
    }

    // Encontrando o sucessor de um valor
    No* sucessor_resultado = sucessor(raiz, 6);
    if (sucessor_resultado != NULL) {
        printf("Sucessor de 6: %d\n", sucessor_resultado->chave);
    } else {
        printf("Sucessor não encontrado\n");
    }

    // Encontrando o máximo da árvore
    No* maximo_resultado = maximo(raiz);
    if (maximo_resultado != NULL) {
        printf("Máximo da árvore: %d\n", maximo_resultado->chave);
    } else {
        printf("Máximo não encontrado\n");
    }

    // Encontrando o mínimo da árvore
    No* minimo_resultado = minimo(raiz);
    if (minimo_resultado != NULL) {
        printf("Mínimo da árvore: %d\n", minimo_resultado->chave);
    } else {
        printf("Mínimo não encontrado\n");
    }

    return 0;
}
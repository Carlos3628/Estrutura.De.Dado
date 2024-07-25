#include "lista.c"

int main() {
    Lista* list = criarLista();
    inserir(list, 5);
    inserir(list, 2);
    inserir(list, 8);
    inserir(list, 3);
    inserir(list, 1);
    imprimir(list); // Saída: 1 2 3 5 8
    remover(list, 3);
    imprimir(list); // Saída: 1 2 5 8
    No* encontrado = buscar(list, 5);
    if (encontrado != NULL) {
        printf("Valor encontrado: %d\n", encontrado->valor);
    } else {
        printf("Valor não encontrado\n");
    }
    return 0;
}
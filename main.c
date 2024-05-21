#include <stdio.h>

int main() {
    int qtd, i, soma = 0;

    printf("Digite a quantidades de arrays a serem somados: ");
    scanf("%d", &qtd);

    int array[qtd];

    printf("Digite os elementos do array:\n");
    for (i = 0; i < qtd; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (i = 0; i < qtd; i++) {
        soma += array[i];
    }

    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}
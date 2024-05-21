#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas1, colunas1, linhas2, colunas2;


    printf("Digite o número de linhas da matriz 1: ");
    scanf("%d", &linhas1);
    printf("Digite o número de colunas da matriz 1: ");
    scanf("%d", &colunas1);
    printf("Digite o número de linhas da matriz 2: ");
    scanf("%d", &linhas2);
    printf("Digite o número de colunas da matriz 2: ");
    scanf("%d", &colunas2);


    if (colunas1 != linhas2) {
        printf("Erro: O número de colunas da matriz 1 deve ser igual ao número de linhas da matriz 2.\n");
        return 1;
    }


    int **matriz1 = (int **)malloc(linhas1 * sizeof(int *));
    int **matriz2 = (int **)malloc(linhas2 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        matriz1[i] = (int *)malloc(colunas1 * sizeof(int));
    }
    for (int i = 0; i < linhas2; i++) {
        matriz2[i] = (int *)malloc(colunas2 * sizeof(int));
    }


    printf("Digite os elementos da matriz 1:\n");
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Digite os elementos da matriz 2:\n");
    for (int i = 0; i < linhas2; i++) {
        for (int j = 0; j < colunas2; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }


    int **resultado = (int **)malloc(linhas1 * sizeof(int *));
    for (int i = 0; i < linhas1; i++) {
        resultado[i] = (int *)malloc(colunas2 * sizeof(int));
        for (int j = 0; j < colunas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }


    printf("Resultado da multiplicação das matrizes:\n");
    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < linhas1; i++) {
        free(matriz1[i]);
    }
    for (int i = 0; i < linhas2; i++) {
        free(matriz2[i]);
    }
    for (int i = 0; i < linhas1; i++) {
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}

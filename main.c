#include <stdio.h>
#include <stdlib.h>


struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};


float calcularTotal(struct Produto produtos[], int numProdutos) {
    float total = 0;
    for (int i = 0; i < numProdutos; i++) {
        total += produtos[i].preco * produtos[i].quantidade;
    }
    return total;
}

int main() {
    int numProdutos;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &numProdutos);

   
    struct Produto *produtos = (struct Produto *)malloc(numProdutos * sizeof(struct Produto));

    
    for (int i = 0; i < numProdutos; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
    }

    
    printf("\nInformações dos Produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
    }

    
    float total = calcularTotal(produtos, numProdutos);
    printf("\nValor total em estoque: %.2f\n", total);

    
    free(produtos);

    return 0;
}

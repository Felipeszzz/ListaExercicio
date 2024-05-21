#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    int idade;
} Pessoa;


int compara_idade(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;

    return (pessoaA->idade - pessoaB->idade);
}

int main() {
    int n;

    
    printf("Quantas pessoas você quer inserir? ");
    scanf("%d", &n);

    
    Pessoa *pessoas = malloc(n * sizeof(Pessoa));
    if (pessoas == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    
    for (int i = 0; i < n; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
    }

   
    qsort(pessoas, n, sizeof(Pessoa), compara_idade);

    
    printf("\nArray ordenado por idade:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
    }

    
    free(pessoas);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILENAME "funcionarios.dat"

typedef struct {
    char nome[MAX_NAME_LENGTH];
    int idade;
    float salario;
} Funcionario;

void adicionarFuncionario();
void listarFuncionarios();
void buscarFuncionario();

int main() {
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Adicionar novo funcionario\n");
        printf("2. Listar todos os funcionarios\n");
        printf("3. Buscar funcionario por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                adicionarFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                buscarFuncionario();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}

void adicionarFuncionario() {
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Funcionario funcionario;
    printf("Digite o nome do funcionario: ");
    fgets(funcionario.nome, MAX_NAME_LENGTH, stdin);
    size_t len = strlen(funcionario.nome);
    if (len > 0 && funcionario.nome[len - 1] == '\n') {
        funcionario.nome[len - 1] = '\0';
    }

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);
    getchar();  

    fwrite(&funcionario, sizeof(Funcionario), 1, file);

    fclose(file);
    printf("Funcionario adicionado com sucesso!\n");
}

void listarFuncionarios() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Funcionario funcionario;
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        printf("Nome: %s\n", funcionario.nome);
        printf("Idade: %d\n", funcionario.idade);
        printf("Salario: %.2f\n\n", funcionario.salario);
    }

    fclose(file);
}

void buscarFuncionario() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char nomeBusca[MAX_NAME_LENGTH];
    printf("Digite o nome do funcionario para buscar: ");
    fgets(nomeBusca, MAX_NAME_LENGTH, stdin);
    size_t len = strlen(nomeBusca);
    if (len > 0 && nomeBusca[len - 1] == '\n') {
        nomeBusca[len - 1] = '\0';
    }

    Funcionario funcionario;
    int encontrado = 0;
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        if (strcmp(funcionario.nome, nomeBusca) == 0) {
            printf("Funcionario encontrado:\n");
            printf("Nome: %s\n", funcionario.nome);
            printf("Idade: %d\n", funcionario.idade);
            printf("Salario: %.2f\n", funcionario.salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Funcionario nao encontrado.\n");
    }

    fclose(file);
}

#include <stdio.h>
#include <ctype.h>

int contar_vogais(char *string) {
    int contador = 0;
    while (*string) {
        char c = *string;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
        string++;
    }
    return contador;
}

int main() {
    char texto[100];
    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin);

    int numero_vogais = contar_vogais(texto);
    printf("Número de vogais na string: %d\n", numero_vogais);

    return 0;
}
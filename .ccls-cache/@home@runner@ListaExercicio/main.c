#include <stdio.h>
#include <ctype.h>


void maiuscula(char *str) {
    char *ptr = str; 

    while (*ptr != '\0') { 
        if (islower(*ptr)) { 
            *ptr = toupper(*ptr); 
        }
        ptr++; 
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str),stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Original: %s\n", str);
    maiuscula(str);
    printf("Maiúsculas: %s\n", str);

    return 0;
}

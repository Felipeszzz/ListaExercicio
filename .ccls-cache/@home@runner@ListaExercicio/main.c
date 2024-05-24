#include <stdio.h>
#include <stdlib.h>


void imprimirArray(int* array, int tamanho) {
for (int i = 0; i < tamanho; i++) {
printf("%d ", array[i]);
}
printf("\n");
}


int* inverterArray(int* array, int tamanho) {
if (array == NULL || tamanho <= 0) {
printf("Entrada inválida\n");
return NULL;
}


int* arrayInvertido = (int*)malloc(tamanho * sizeof(int));
if (arrayInvertido == NULL) {
printf("Erro de alocação de memória\n");
exit(1); 
}


int* ptrOriginal = array + tamanho - 1;
int* ptrInvertido = arrayInvertido;


while (ptrOriginal >= array) {
*ptrInvertido = *ptrOriginal;
ptrOriginal--;
ptrInvertido++;
}


return arrayInvertido;
}

int main() {
int tamanho;


printf("Digite o tamanho do array: ");
scanf("%d", &tamanho);


if (tamanho <= 0) {
printf("Tamanho inválido\n");
return 1;
}


int* array = (int*)malloc(tamanho * sizeof(int));
if (array == NULL) {
printf("Erro de alocação de memória\n");
return 1;
}


printf("Digite os elementos do array:\n");
for (int i = 0; i < tamanho; i++) {
printf("Elemento %d: ", i + 1);
scanf("%d", &array[i]);
}


int* arrayInvertido = inverterArray(array, tamanho);
if (arrayInvertido != NULL) {
printf("Array invertido: ");
imprimirArray(arrayInvertido, tamanho);


free(arrayInvertido);
}


free(array);

return 0;
}
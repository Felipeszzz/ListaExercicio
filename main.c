#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
return (*(int*)a - *(int*)b);
}


double calcularMedia(int arr[], int tamanho) {
int soma = 0;
for(int i = 0; i < tamanho; i++) {
soma += arr[i];
}
return (double)soma / tamanho;
}


double calcularMediana(int arr[], int tamanho) {
qsort(arr, tamanho, sizeof(int), compare);
if (tamanho % 2 == 0) {
return (arr[tamanho/2 - 1] + arr[tamanho/2]) / 2.0;
} else {
return arr[tamanho/2];
}
}


int calcularModa(int arr[], int tamanho) {
qsort(arr, tamanho, sizeof(int), compare);

int moda = arr[0];
int maxContagem = 1;
int contagemAtual = 1;

for(int i = 1; i < tamanho; i++) {
if(arr[i] == arr[i - 1]) {
contagemAtual++;
} else {
if(contagemAtual > maxContagem) {
maxContagem = contagemAtual;
moda = arr[i - 1];
}
contagemAtual = 1;
}
}

if(contagemAtual > maxContagem) {
moda = arr[tamanho - 1];
}

return moda;
}

int main() {
int n;
printf("Digite o número de elementos do array: ");
scanf("%d", &n);

if (n <= 0) {
printf("O número de elementos deve ser maior que zero.\n");
return 1;
}

int *arr = (int*)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Erro de alocação de memória.\n");
return 1;
}

printf("Digite os elementos do array:\n");
for(int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

double media = calcularMedia(arr, n);
double mediana = calcularMediana(arr, n);
int moda = calcularModa(arr, n);

printf("Média: %.2f\n", media);
printf("Mediana: %.2f\n", mediana);
printf("Moda: %d\n", moda);

free(arr);
return 0;
}
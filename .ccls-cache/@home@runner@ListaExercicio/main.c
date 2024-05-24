#include <stdio.h>
#include <time.h>

unsigned long long fatorial(int n) {
if (n == 0 || n == 1) {
return 1;
}
return n * fatorial(n - 1);
}

int main() {
int num;
unsigned long long result;
clock_t start, end;
double cpu_time_used;


printf("Digite um número para calcular o fatorial: ");
scanf("%d", &num);


start = clock();


result = fatorial(num);

end = clock();


cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


printf("O fatorial de %d é %llu\n", num, result);
printf("Tempo de execução: %f segundos\n", cpu_time_used);

return 0;
}


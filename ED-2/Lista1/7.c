#include <stdio.h>
#include <stdlib.h> // Necessário para qsort
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int compare_pares(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função de comparação para ordenar os ímpares em ordem decrescente
int compare_impares(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N;
    scanf("%d", &N);

    int pares[N];
    int impares[N];
    int count_pares = 0;
    int count_impares = 0;
    int num;

    // Lendo e separando os números
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            pares[count_pares++] = num;
        } else {
            impares[count_impares++] = num;
        }
    }

    // Ordenando os arrays usando qsort
    // qsort(array, número de elementos, tamanho de cada elemento, função de comparação)
    qsort(pares, count_pares, sizeof(int), compare_pares);
    qsort(impares, count_impares, sizeof(int), compare_impares);

    // Imprimindo os resultados
    for (int i = 0; i < count_pares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < count_impares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
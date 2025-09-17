#include <stdio.h>
//Aluno: Gustavo Souza Rocha
//Matricula: 20232003300021
int soma(int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + soma(v, n - 1);
}
int main(void) {
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", soma(v, 10));
    return 0;
}
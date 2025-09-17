#include <stdio.h>
//Aluno: Gustavo Souza Rocha
//Matrícula: 20232003300021
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int x = 10, y = 20;
    trocar(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

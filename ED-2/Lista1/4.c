#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int valor, total, n1, n2, n5, n10, n20, n50, n100;
    scanf("%d", &valor);
    total = valor;
    n100 = valor / 100;
    valor -= n100 * 100;
    n50 = valor / 50;
    valor -= n50 * 50;
    n20 = valor / 20;
    valor -= n20 * 20;
    n10 = valor / 10;
    valor -= n10 * 10;
    n5 = valor / 5;
    valor -= n5  * 5;
    n2 = valor / 2;
    valor -= n2 * 2;
    n1 = valor;
    
    printf("%d\n", total);
    printf("%d nota(s) de R$ 100,00\n", n100);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);
}
#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int dias, meses, anos;
    scanf("%d", &dias);
    anos = dias / 365;
    dias %= 365;
    meses = dias / 30;
    dias %= 30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
}
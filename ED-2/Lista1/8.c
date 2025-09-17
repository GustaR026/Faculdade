#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int x, i;
    scanf("%d", &x);
    for(i = 1; i <= 10000; i++)
    {
        if(i % x == 2)
        {
            printf("%d\n", i);
        }
    }
}
#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int x[10], i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
        if(x[i] <= 0)
        {
            x[i] = 1;
        }
        printf("X[%d] = %d\n", i, x[i]);
    }
}
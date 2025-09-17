#include <stdio.h>
#include <math.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int n, i, q, c;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        q = pow(i, 2);
        c = pow (i, 3);
        printf("%d %d %d\n", i, q, c);
    }
}
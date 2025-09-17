#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int i, j, n, p;
    long long fib[61];
    fib[0] = 0;
    fib[1] = 1;
    for(j = 2; j < 61; j++)
    {
        fib[j] = fib[j - 1] + fib[j - 2];
    }
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p);
        printf("Fib(%d) = %lld\n", p, fib[p]);
    }    
}    
#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    double m[12][12], soma = 0, media;
    int i, j, k = 1;
    char O;
    scanf("%c", &O);
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {
            scanf("%lf", &m[i][j]);
        }
    }
    for(i = 0; i < 5 ; i++)
    {
        for(j = 0 + k; j < 12 - k; j++)
        {
            soma += m[i][j];
        }
        k++;
    }
    if(O == 'S')
    {
        printf("%.1lf\n", soma);
    }
    else
    {
        media = soma / 30.0;
        printf("%.1lf\n", media);
    }
}

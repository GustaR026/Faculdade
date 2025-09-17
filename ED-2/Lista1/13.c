#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main()
{
    int i, j, l;
    double M[12][12], soma = 0, media;
    char T;
    scanf("%d %c", &l, &T);
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {           
            scanf("%lf", &M[i][j]);  
        }
    }           
    for(j = 0; j < 12; j++)
    {
        soma += M[l][j];
    }
    if(T == 'S')
    {
        printf("%.1lf\n", soma);
    }
    else
    {
        media = soma / 12.0;
        printf("%.1lf\n", media);
    }
    
}
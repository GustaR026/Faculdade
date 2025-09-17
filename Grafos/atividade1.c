#include <stdio.h>

int main() {
    int n, m;
    printf("Digite as dimensoes da matriz:\n");
    scanf("%d %d", &n, &m);
    while (n != m) {
        printf("Informe dimensoes validas!!!\n");
        printf("Digite as dimensoes da matriz:\n");
        scanf("%d %d", &n, &m);
    }

    int mat[n][n];
    printf("Informe a matriz: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            while (mat[i][j] != 1 && mat[i][j] != 0) {
                printf("Informe valores validos!!!\n");
                scanf("%d", &mat[i][j]);
            }
            if (i == j) {
                while (mat[i][j] != 0) {
                    printf("Informe valores validos!!\n");
                    scanf("%d", &mat[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (mat[i][j] != mat[j][i]) {
                printf("Informe valores validos!!\n");
                scanf("%d %d", &mat[i][j], &mat[j][i]);
            }
        }
    }

    int soma;
    printf("Grau dos vertices: \n");
    for (int i = 0; i < n; i++) {
        soma = 0;
        for (int j = 0; j < n; j++) {
            soma += mat[i][j];
        }
        printf("Grau %d: %d\n", i, soma);
    }

}
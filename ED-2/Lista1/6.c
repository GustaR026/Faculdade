#include <stdio.h>
#include <string.h>
//Aluno: Gustavo Souza Rocha
//Matrícula: 20232003300021

#define MAX 55

static void strip_eol(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
    }
}

int main(void) {
    char a[MAX], b[MAX];

    // Loop principal: lê duas strings por vez da entrada padrão
    while (fgets(a, sizeof a, stdin) && fgets(b, sizeof b, stdin)) {
        strip_eol(a);
        strip_eol(b);

        int n = strlen(a);
        int m = strlen(b);
        
        // Matriz para armazenar comprimentos de substrings comuns
        int mat[MAX][MAX] = {{0}};
        int maxLen = 0;

        // Loop aninhado para preencher a matriz dp
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Se os caracteres atuais forem iguais...
                if (a[i-1] == b[j-1]) {
                    // ... estende a substring comum
                    mat[i][j] = mat[i-1][j-1] + 1;
                    // Atualiza o comprimento máximo, se necessário
                    if (mat[i][j] > maxLen) {
                        maxLen = mat[i][j];
                    }
                } else {
                    // Se os caracteres forem diferentes, a substring é quebrada
                    mat[i][j] = 0;
                }
            }
        }

        printf("%d\n", maxLen);
    }
    return 0;
}
#include <stdio.h>
// Aluno: Gustavo Souza Rocha
// Matrícula: 20232003300021
int main() {
    int a, b;
    int m2 = 0, m3 = 0, m4 = 0, m5 = 0;
    scanf("%d", &a);
    for(int i = 0; i < a; i++) {
        scanf("%d", &b);
        if (b % 2 == 0) {
            m2++;
        }
        
        if(b % 3 == 0){
            m3++;
        }
            
        if(b % 4 == 0){
            m4++;
        }
                
        if(b % 5 == 0){
            m5++;
        }       
    }
    printf("%d Multiplo(s) de 2\n", m2);
    printf("%d Multiplo(s) de 3\n", m3);
    printf("%d Multiplo(s) de 4\n", m4);
    printf("%d Multiplo(s) de 5\n", m5);
}
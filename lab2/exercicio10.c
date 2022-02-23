#include <stdio.h>

void multiplica_linha(int m[2][2], int n){
    for(int i = 0; i < 2; i++){
        m[0][i] *= n;
    }
}

void multiplica_coluna(int m[2][2], int n){
    for(int i = 0; i < 2; i++){
        m[i][0] *= n;
    }
}

void imprime_matriz(int m[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int m[2][2] = {{3, 4},
                    {5, 6}};
    int n = 5;
    imprime_matriz(m);
    multiplica_linha(m, n);             
    imprime_matriz(m);
    multiplica_coluna(m, n);
    imprime_matriz(m);
    return 0;
}

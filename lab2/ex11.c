#include <stdio.h>


void soma(int m[2][2]){
	for(int i = 0; i < 2; i++){
		m[1][i] += m[0][i];
	}
}

void multiplica(int m[2][2]){
	for(int i = 0; i < 2; i++){
		m[1][i] *= m[0][i];
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
	int m[2][2] = {{3, 4},{5, 6}};
	imprime_matriz(m);
	soma(m);
	imprime_matriz(m);
	multiplica(m);
	imprime_matriz(m);
	return 0;
}

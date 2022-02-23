#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(int **m){
	int i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int **transposta(int m[2][2]){
	int **m_t = malloc(sizeof(int*) * 2);
	for(int i = 0; i < 2; i++){
		m_t[i] = malloc(sizeof(int) * 2);
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			m_t[j][i] = m[i][j];
		}
	}
	return m_t;
}


int main(void){
	int m[2][2] = {{-3, -4},
			 	   {-5, -6}};
	int **m_t = transposta(m);
	imprime_matriz(m_t);
	return 0;
}

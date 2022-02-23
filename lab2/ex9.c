#include <stdio.h>

void modulo_matriz(int m[2][2]){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(m[i][j] < 0){
				m[i][j] *= -1;
			}
		}
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
	int m[2][2] = {{-3, -4},
			 	   {-5, -6}};
	imprime_matriz(m);
	modulo_matriz(m);
	imprime_matriz(m);
	return 0;
}

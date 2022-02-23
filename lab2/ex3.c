#include <stdio.h>
#include <string.h>
#define TAM 20

int main(void){
	char nome1[TAM], nome2[TAM];
	scanf("%s %s", nome1, nome2);

	if (memcmp(nome1, nome2, sizeof(nome1)) > 0){
		printf("%s\n%s", nome2, nome1);
	}
	else{
		printf("%s\n%s", nome1, nome2);
	}
	
	return 0;
}

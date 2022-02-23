#include <stdio.h>
#include <string.h>
#include <iostream>


void imprime_ordenado_c(char *nome1, char *nome2){
	int n = memcmp(nome1, nome2, sizeof(nome1)/sizeof(char));
	if(n < 0){
		printf("%s\n%s\n", nome1, nome2);
		return;
	}
	printf("%s\n%s\n", nome2, nome1);
}

void imprime_ordenado_maismais(std::string s1, std::string s2){
	if(s1 < s2){
		std::cout << s1 << std::endl << s2;
		return;
	}
	std::cout << s2 << std::endl << s1;
}

int main(void){
	char *nome1 = "Victor";
	char *nome2 = "Abram";
	std::string s1 = "Victor";
	std::string s2 = "Abram";
	imprime_ordenado_c(nome1, nome2);
	imprime_ordenado_maismais(s1, s2);
	return 0;
}

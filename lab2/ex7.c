#include <stdio.h>

typedef struct pessoa{
	char *nome;
	int idade;
	float peso, altura;
}Pessoa;

void imprime_dados_pessoa(Pessoa p){
	printf("Nome: %s\nIdade: %d\nPeso: %.1f\nAltura: %.2f\n", p.nome, p.idade, p.peso, p.altura);
}

int main(void){
	Pessoa p1, p2, p3;
	Pessoa pessoas[3] = {p1, p2, p3};
	char nome_p1[20], nome_p2[20], nome_p3[20];
	printf("Digite o nome das 3 pessoas separados por espaços: ");
	scanf("%20s %20s %20s", nome_p1, nome_p2, nome_p3);
/*	printf("%s %s %s", nome_p1, nome_p2, nome_p3);*/
	p1.nome = nome_p1; p2.nome = nome_p2; p3.nome = nome_p3;
	imprime_dados_pessoa(p1);
	imprime_dados_pessoa(p2);
	imprime_dados_pessoa(p3);
	return 0;
}

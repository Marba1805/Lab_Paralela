#include <stdio.h>

void insere_caracter(char c,int p, char *Str){
	Str[p] = c;
}

int main(void){
	char Str[100];
	char c = 'b';
	int p = 2;
	insere_caracter(c, p, Str);
	printf("%c", Str[p]);
	return 0;
}

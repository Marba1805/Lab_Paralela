#include <stdio.h>

void remove_caracter(int p, char Str[100]){
	Str[p] = NULL;
}

int main(void){
	int p = 5;
	char Str[100] = {'h'};
	remove_caracter(p, Str);
	printf("%c", Str[p]);
	return 0;
}

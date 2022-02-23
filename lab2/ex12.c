#include <stdio.h>

int busca(char c, char *str){
	for(int i = 0; str[i] != '\0'; i++){
		if(c == str[i]){
			return i;
		}
	}
	return -1;
}

int main(void){
	char str[] = {'b','l','a','b','l','a'};
	printf("%d\n%d", busca('l', str), busca('h', str));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

struct PESSOA{
    char nome[200];
    int idade;
    int altura;
};

int main()
{
    char S1[50];
    PESSOA Povo[10], P;
    FILE *Arq;
    int i,c;
	c = 0;
	struct PESSOA a;
	std::ofstream arq;
	arq.open("arquivo.txt");
     if (arq.is_open())
     {
            {
            	while(!arq.eof())
            	{
            		if (c%3 == 0)
                    {
                    	a.nome = 
                    	c++;
                    }
             		if (c%3 == 1)
                    {
                     	a.idade
						c++; 
                    }
            		if (c%3 == 2)
                    {
						a.altura
						c++;
                    }

				}

            } while(1);
            fechaArquivo(Arq);
            ordenaVetor(Povo, i);
            imprimeVetor(Povo,i);
    }
    else printf("Erro na abertura do arquivo");
     return 0;

}

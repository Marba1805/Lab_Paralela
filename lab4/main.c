#include <stdio.h>
#include <cstdlib>

struct PESSOA{
    char Nome;
    int idade;
    int altura;
};

int main()
{
     char S1[50];
     PESSOA Povo[10], P;
     FILE *Arq;
     int i;

     leNomeArquivoEntrada(S1);
     if (abreArquivoAEntrada(Arq, S1) == 1)
     {
            do{
                    if (leDadosUmaPessoa(P)== 1)
                    {
                        Povo[i] = P;
                        i++;
                    }
                    else break;
            } while(1);
            fechaArquivo(Arq);
            ordenaVetor(Povo, i);
            imprimeVetor(Povo,i);
    }
    else printf("Erro na abertura do arquivo");
     return 0;

}

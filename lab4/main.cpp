#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <iostream>

struct PESSOA{
    std::string nome;
    int idade;
    float altura;
};

int compare (const void * a, const void * b){
  PESSOA *PESSOAA = (PESSOA *)a;
  PESSOA *PESSOAB = (PESSOA *)b;

  return ( PESSOAB->altura - PESSOAA->altura );
}

char *leArquivo(char *nomeArquivo){
    int tamArquivo;
    char *buffer;
    FILE *fp;
    fp = fopen(nomeArquivo,"r"); // abre o arquivo
    if( fp == NULL ){
        printf("Erro na abertura do arquivo %s",nomeArquivo);
        exit(-1);
    }
    fseek (fp, 0, SEEK_END);  // vai para o final do arquivo
    tamArquivo = ftell(fp);
    rewind (fp);
    // alocar um buffer de leitura
    buffer = (char *) calloc(tamArquivo+1, sizeof(char));

    // le todo arquivo
    fread(buffer,1,tamArquivo,fp);
    fclose(fp); // fecha o arquivo
    return buffer;
}

int main()
{
    int i = 0, j = 0, k = 0;
    PESSOA Povo[10], P;
    char *entrada = leArquivo("arquivo.txt");
    std::string nome, idade, altura, linha;
    while(entrada[i] != '\0'){
//    	linha += entrada[i];
    	if(entrada[i] == '\n'){
    		if(k%3 == 0){
    			Povo[j].nome = linha;
    			linha.clear();
    			k++;
			}
			else if(k%3 == 1){
				Povo[j].idade = atoi(linha.c_str());
				linha.clear();
    			k++;
			}
			else if(k%3 == 2){
				Povo[j].altura = atof(linha.c_str());
				linha.clear();
    			k++;
    			j++;
			}
		}
		else {
			linha += entrada[i];
		}
		i++;
	}
	std::cout << "Vetor antes da ordenacao" << std::endl;
	for(int m = 0; m < 4; m++){
		std::cout << "Nome: " << Povo[m].nome << std::endl;
		std::cout << "Idade: " << Povo[m].idade << std::endl;
		std::cout << "Altura: " << Povo[m].altura << std::endl << std::endl;
	}
	
	qsort (Povo, 4, sizeof(PESSOA), compare);
	
	std::cout << "Vetor depois da ordenacao" << std::endl;
	std::string saida;
	for(int m = 0; m < 4; m++){
		saida += Povo[i].nome
	}
	FILE *fOutPtr;
	fOutPtr = fopen("saida.txt", "w");
	if(fOutPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 4; i++){
    	fputs("%s\n%d\n%f\n", Povo[i].nome.c_str(), Povo[i].idade, Povo[i].altura);
	}
    fclose(fOutPtr);
	
    return 0;

}
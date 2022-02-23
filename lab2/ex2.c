#include <stdio.h>

float *recebe_notas (void);
float calcula_media (float *notas);
char informa_conceito (float media);

float *recebe_notas (void){
	float notas[4];
	
	scanf("%f %f %f %f", &notas[0], &notas[1], &notas[2], &notas[3]);
	
	return notas;
}

float calcula_media (float *notas){
	float somatoria_com_peso, resultado;
	
	somatoria_com_peso = (*notas)+(notas[1]*2)+(notas[2]*3)+(notas[3]);
	resultado = somatoria_com_peso/7;

	return resultado;
}

char informa_conceito (float media){
	if (media >= 9){
		return 'A';
	}
	else if (media >= 7.5){
		return 'B';
	}
	else if (media >= 6){
		return 'C';
	}
	else if (media >= 4){
		return 'D';
	}
	else{
		return 'E';
	}
}

int main (void){
	float *notas, media;
	char conceito;
	
	printf("\nAs notas devem ser informadas na sequencia (N1, N2, N3, ME)\n");
	printf("\nInsira aqui as 4 notas separadas por espacos: ");
	
	notas = recebe_notas();
	media = calcula_media(notas);
	conceito = informa_conceito(media);
	
	printf("\nO conceito atingido pelo aluno foi: %c\nSua media foi: %f", conceito, media);
	return 0;
}

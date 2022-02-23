#include<stdio.h>


void multiplica_linha(int m[2][2], int n){
    for(int i = 0; i < 2; i++){
        m[0][i] *= n;
    }
}

void multiplica_coluna(int m[2][2], int n){
    for(int i = 0; i < 2; i++){
        m[i][0] *= n;
    }
}


int main(void)
{

int i,j,k;

int mat[2][2];

printf("Entre os elementos da sua matriz\n");  
for(i=0;i<2;i++)
{
  for(j=0;j<2;j++)
  {  
    scanf("%d",&mat[i][j]);  
  } 
  
}
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{	  
		printf("%d",mat[i][j],"\n");  
	} 
	printf("\n");
}

printf("Entre por quanto voce quer multiplicar \n a linha da matriz que voce quer multiplicar:\n");
scanf("%d", &k);
multiplica_coluna(mat, k);
for(i=0;i<2;i++)
{
  for(j=0;j<2;j++)
  {  	  
		printf("%d",mat[i][j],"\n");  
	} 
	printf("\n");
	
}

return 0;

}

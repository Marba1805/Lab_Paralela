#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h> 
#include <errno.h>
#include <sys/ipc.h>

int main(void)
{
  pid_t cpid;   
  int shm_id;
  
  if ((shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0770)) == -1){
      printf("Erro no shmget ");
      exit(1);
    }
  
  int *varCompart = (int*) shmat(shm_id, NULL, 0);
  *varCompart = 1;

  cpid = fork();
    
  if (cpid<0)
    {
        printf("falha na criacao do filho\n");
        exit(0);
    }

  else if (cpid == 0)
  {
    printf("Valor inicial variavel compartilhada inicial = %i\n", *varCompart);
    *varCompart = *varCompart + 5;
    printf("Valor da variavel compartilhada apos somar 5 = %i\n", *varCompart);
  }

  else if (cpid > 0)
  {
    wait(NULL);
    *varCompart = *varCompart * 10;
    printf("Valor da variavel compartilhada apos multiplicar por 10 = %i", *varCompart);
    }
}

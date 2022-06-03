#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


// para compilar:
// gcc -o tartaruga4 tartaruga4.c -lpthread
int x, thread_count;

typedef struct info_threads{
  int rank;
  int inicio;
  int fim;
}info_threads;

void *T(void *info);

sem_t  s;

int main(int argc, char *argv[]){
  // if(argc != 3){
  //   printf("%s\nUtilizacao: insira o x para T(x) como primeiro argumento, e o número de threads como segundo argumento.\nOBS: x precisa ser divisível pelo número de threads.\n", argv[0]);
  //   exit(1);
  // }
  int sem;
  long thread;
  pthread_t *thread_handles;
  x = strtoull(argv[1], NULL, 10);
  thread_count = strtol(argv[2], NULL, 10);
  sem = thread_count/4;
  sem_init(&s, 0, sem);

  /*
   * Divide o numero de threads e compara-o a ate quanto quer fazer aconta
   * e se nao der resto 0 retorna erro 
   */
  if(x%thread_count!=0){
    printf("Numero de threads nao divide x.\n");
    exit(EXIT_FAILURE);
  }
  int incremento = x/thread_count;

  thread_handles = malloc (thread_count*sizeof(pthread_t));
  /*
    * Cria-se as threds e ja coloca-se nelas tanto o ponto inical a ser
    * feita as contas 
    * 2^40= 1099511627776
    */
  for (thread = 0; thread < thread_count; thread++){
    info_threads *a = malloc(sizeof(info_threads));
    a->rank = thread;
    a->inicio = thread*incremento;
    a->fim = a->inicio+incremento;
    if(pthread_create(&thread_handles[thread], NULL, T,(void*) a) != 0){
      printf("Falha na criacao da thread %d.\nTerminando o programa.\n", (int)thread);
      exit(EXIT_FAILURE);
    }
  }

    /*
    * Enserra-se as threads e faz-se a soma dos resultados retornados delas
    */
  long double soma_global = 0;
  for(thread = 0; thread < thread_count; thread++){
    long double *resultado_thread;
    if(pthread_join(thread_handles[thread], (void**) &resultado_thread) != 0){
      printf("Falha na junção da thread %d\n", (int)thread);
      exit(EXIT_FAILURE);
    }
    soma_global+=*resultado_thread;
    free(resultado_thread);
  }
  sem_destroy(&s);
  printf("Soma global: %0.32Lf\n", soma_global);
}


void *T(void* info){
  info_threads *infot = (info_threads*) info;
  int rank = infot->rank;
  int inicio = infot->inicio+1;
  int fim = infot->fim+1;
  long double resultado = 0;
  long double *res = malloc(sizeof(float));
  sem_wait(&s);
  
  for(int i = inicio; i < fim; i++){
    resultado += (double)1/i;
  }
  *(long double*)res = resultado;
  printf("Resultado da thread %d = %.32Lf\n", rank, *res);
  sem_post(&s);
  return res;
}

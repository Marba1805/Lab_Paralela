#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 2

void *T(void* rank);

int main(void){
  pthread_t t1, t2;
  long it1 = 1, it2 = 6;
  float *r1, *r2;
  if(pthread_create(&t1, NULL, T, (void*) it1) != 0){
    printf("Failed to create thread.\n");
  }
  if(pthread_create(&t2, NULL, T, (void*) it2) != 0){
    printf("Failed to create thread.\n");
  }
  if(pthread_join(t1, (void**) &r1) != 0){
    printf("Failed to join thread.\n");
  }
  if(pthread_join(t2, (void**) &r2) != 0){
    printf("Failed to join thread.\n");
  }
  float resultado_final = *(r1)+*(r2);
  printf("T(10) = %f", resultado_final);
  free(r1);
  free(r2);
}

void *T(void* rank){
  long i = (long) rank;
  float resultado = 0;
  float* res = malloc(sizeof(float));
  int j;
  for(j = 0; j < 5; j++, i++){
    resultado += (float)1/i;
  }
  *res = resultado;
  return (void*) res;
}

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <semaphore.h>
#define MAX 10000000000000

static int32_t contador;
static sem_t semaforo;

void *contar(void *args){
	sem_wait(&semaforo);
	int32_t i;
	for(i = 0; i<MAX; i++)
		contador++;
	sem_post(&semaforo);
	pthread_exit(NULL);
}
int main(void){
	pthread_t hilos[5];
	int32_t i;
	sem_init(&semaforo,0,1);
	for(i=0; i<5; i++)
		pthread_create(&hilos[i], NULL,(void*)contar,NULL);
	for(i=0; i<5; i++)
		pthread_join(hilos[i], NULL);
	printf("El resultado es: %d\n",contador );
	
	return 0;
}
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <semaphore.h>
#define MAX 100000

static int32_t contador;
//static sem_t semaforo;
pthread_mutex_t semaforo;


void *contar(void *args){
	//sem_wait(&semaforo);
	int32_t i;
	pthread_mutex_lock(&semaforo);
	for(i = 0; i<MAX; i++)
		contador++;
	pthread_mutex_unlock(&semaforo);
	//sem_post(&semaforo);
	pthread_exit(NULL);
}
int main(void){
	pthread_t hilos[5];
	pthread_mutex_init(&semaforo, NULL);
	int32_t i;
	//sem_init(&semaforo,0,1);
	//pthread_mutex_lock(pthread_mutex_t *mutex);
	for(i=0; i<5; i++)
		pthread_create(&hilos[i], NULL,(void*)contar,NULL);
	for(i=0; i<5; i++)
		pthread_join(hilos[i], NULL);
	printf("El resultado es: %d\n",contador );
	pthread_mutex_destroy(&semaforo);
	
	return 0;
}
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//instancia de hilos
pthread_t tid[2];
int ret1;
int ret2;

void *hacerAlgo(void *arg);
int main(void){
	int i = 0;
	int err;
	int *valor[2];
	while(i<2){
		err = pthread_create(&(tid[i]), NULL, &hacerAlgo, NULL);
		if(err != 0){
			printf("\nNo se pudo: [%s]", strerror(err));
		}
		else{
			printf("\nSi se pudo cainal\n");
		}
		i++;
	}
	pthread_join(tid[0], (void**)&(valor[0]));
	pthread_join(tid[1], (void**)&(valor[1]));
	printf("\nValor de retorno del primer hilo: [%d]\n", *valor[0]);
	printf("\nValor de retorno del primer hilo: [%d]\n", *valor[1]);
	return 0;
}

void *hacerAlgo(void *arg){
	unsigned long i = 0;
	pthread_t id = pthread_self();
	//identifica si el hilo es el primero o el segundo
	if(pthread_equal(id, tid[0])){
		printf("\nSoy el primer hilo en proceso ");
		ret1 = 23;
		pthread_exit(&ret1);
	}else{
		printf("\nSoy el segundo\n");
		ret2=57;
		pthread_exit(&ret2);
	}
	for(i = 0; i < 1000000; i++);
	return NULL;
}
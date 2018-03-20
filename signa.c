#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#define MAX_HIJOS 3
#define INTERVALO 5

void temp(int sig);
void misAcciones(int sig);
int hijo[MAX_HIJOS];

int main(){
	int ppid = 0, i, j;
	int contador = 0;
	int pidActual;

	ppid = getpid();
	printf("Padre -> %d\n",ppid);
	for(i = 0; i < MAX_HIJOS; i++){
		pidActual = fork();
	}
	if(pidActual < 0) return -1;
	if(ppid == 0){
		switch (i){
			case 0:
				signal(30, misAcciones);
				printf("Hijo[0] ->%d\n", getpid());
				while(1) pause;
				break;
			case 1:
				signal(10, misAcciones);
				printf("Hijo[1] ->%d\n", getpid());
				while(1) pause;
				break;
			case 2:
				signal(16, misAcciones);
				printf("Hijo[2] ->%d\n", getpid());
				while(1) pause;
				break;
		}
	}
	hijo[contador] = pidActual;
	if(signal(SIGALRM, temp) == SIG_ERR)
		printf("No fue posible cambia la accion\n");
	alarm(INTERVALO);
	while(1) pause();
	return 0;
}

void temp(int sig){
	printf("Temp: Me llamo %i\n", getpid());
	kill(hijo[0], 30);
	kill(hijo[1], 0);
	kill(hijo[2], 16);
	alarm(INTERVALO);
}

void misAcciones(int sig){
	int i, j;
	switch(sig){
		case 30:
			for(i = 0; i < 30000; i++);
			printf("Me llamo %i, con la senial %i\n",getpid(), sig);
			break;
		case 10:
			for(i = 0; i < 30000; i++);
			printf("Me llamo %i, con la senial %i\n",getpid(), sig);
			break;
		case 16:
			printf("Me llamo %i, con la senial %i\n",getpid(), sig);
			for(i = 0; i < 100000; i++)
				for(j = 0; j < 100000; j++);
			printf("Me llamo %i, con la senial %i\n",getpid(), sig);

			break;
	}
}
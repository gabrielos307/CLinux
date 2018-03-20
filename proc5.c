#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("Ejemplo de proceso huerfano\n");
	printf("Inicio del proceso padre. PID = %d\n",getpid());
	if(fork()==0){
		printf("Inicio del proceso chaild :v PID = %d, PPID = %d\n", getpid(), getppid());
		sleep(1); 
		printf("El proceso queda como Batman :c. PID = %d, PPID = %d\n", getpid(), getppid());
	}else
		printf("Continuacion del padre PID = %d\n", getpid());
	printf("Fin del proceso %d\n",getpid());
}
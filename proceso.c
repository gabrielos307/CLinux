#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	printf("Soy el programa principal\n");
	pid = fork();
	if(pid < 0){
		printf("Error en la creacion del proceso hijo\n");

	}else if(pid != 0){
		printf("HOLA PERRO, SOY SU PADRE\n");
		printf("Mi hijo tiene el id: %d",pid);
	}else{
		printf("Yo soy el hijo ctm y tengo el hijo: %d\n",getpid());
		printf("Mi padre tiene el id: %d\n", getppid());
	}
	return 0;

}
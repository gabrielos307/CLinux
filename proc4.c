#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

int main(void){
	pid_t hijo;
	if((hijo = fork())){
		printf("Soy el hijo padre y espero 60 seg antes de terminar");
		printf("De mi hijo %d no se nada :'v\n", hijo);
		sleep(60);
	}else
		exit(EXIT_SUCCESS);

	return EXIT_SUCCESS;
	
}
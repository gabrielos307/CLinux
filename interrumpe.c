#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int bucle = 1;
void despedida();

int main(){

	signal(SIGINT, despedida);
	while(1){
		printf("No se hace nada\n");
	}
	return 0;
}

void despedida(){
	printf("----------------\n");
	printf("Que te paza calabaza\n");
	printf("----------------\n");
	raise(SIGTERM);
}
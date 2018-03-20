#include <stdio.h>
#include <signal.h>

int num_pulsaciones = 0 , bucle = 1;
void terminar_bucle();
void contar();

int main(int argc, char const *argv[]){
	signal(SIGINT, contar);
	signal(SIGALRM, terminar_bucle);
	printf("Pulsa varias vece CTRL durante 15 segundos\n");
	alarm(15);
	while(bucle == 1);
	signal(SIGINT, SIG_IGN);
	printf("Has pulsado CTRL-C %d veces\n", num_pulsaciones);
	return 0;
}

void terminar_bucle(){
	signal(SIGALRM, SIG_IGN);
	bucle = 0;
	printf("Alarma\n");
}

void contar(){
	signal(SIGINT, SIG_IGN); //recibe que señal y una funcion
	printf("Haz pulsado CTRL-C\n");
	num_pulsaciones++;
	signal(SIGINT, contar);
}

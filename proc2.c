#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int x = 0;

	if(fork()){
		x += 10;
		printf("\nEl proceso padre imprime: %d\n",x);
	}else{
		x -= 5;
		printf("El proceso hijo imprime: %d\n", x);
	}
	pid = fork();
	int i;
	for(i = 0; i <3;i++){
		printf("\n");
	}
}
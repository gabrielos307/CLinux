#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	int x;
	for(x = 0; x<3; x++){
		if(fork()){
			printf("Soy el proceso: %d\thijo de: %d\n", getpid(), getppid());
			break;
		}
	}
}
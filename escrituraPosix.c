#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
O_RDONLY se abre solo para lectura 
O_WRONDLY se abre solo para escritura 0700
O_RDWR se abre solo para lectura y escritura
O_CREAT se crea si no ha estado 
*/
int main(int argc, char const *argv[]){
	int archivo; //declaramos una variable 
	char c;
	archivo = open("archivo.txt",O_CREAT);
	scanf("%s", &c);
	printf("%s", &c);
	if(archivo != -1){r
		write(archivo, &c, sizeof(c));
		close(archivo);
	}else{
		printf("El archivo no existe :/\n");
		exit(EXIT_FAILURE);
	}

}
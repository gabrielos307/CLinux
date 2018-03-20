#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
O_RDONLY se abre solo para lectura
O_WRONDLY se abre solo para escritura
O_RDWR se abre solo para lectura y escritura
O_CREAT se crea si no ha estado 
*/
int main(int argc, char const *argv[]){
	int archivo; //declaramos una variable 
	char c;
	archivo = open("ejemplo.txt",O_RDONLY);
	if(archivo != -1){
		while(read(archivo, &c, sizeof(c)!=0)){
			printf("%c\t", c);
		}
		close(archivo);
	}else{
		printf("El archivo no existe :/\n");
		exit(EXIT_FAILURE);
	}

}
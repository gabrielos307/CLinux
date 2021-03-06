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
	int archivo, archivo2; //declaramos una variable 
	char c;
	archivo = open("archivo.txt",O_RDONLY);
	archivo2 = open("archivo2.txt",O_WRONLY);

	if(archivo != -1){
		while(read(archivo, &c, sizeof(c)!=0)){
			write(archivo2, &c, sizeof(c));
		}
		close(archivo);
		close(archivo2);

	}else{
		printf("El archivo no existe :/\n");
		exit(EXIT_FAILURE);
	}
	archivo2 = open("archivo2.txt",O_RDONLY);
	if(archivo2 != -1){
		while(read(archivo2, &c, sizeof(c)!=0)){
			printf("\n%c", c);
		}
		close(archivo2);
	}else{
		printf("El archivo no existe :/\n");
		exit(EXIT_FAILURE);
	}


}
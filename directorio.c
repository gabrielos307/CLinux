#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>


void main(int argc, const char *argv[]){
	DIR *directorio;
	struct dirent *dp;
	char cadena[256];
	//Imprimimos el directorio actual
	getcwd(cadena, 256); //funcion que nos muestra nuestro directorio 
	printf("Directorio actual: %s", cadena);
	//abre el directorio pasado como argumento

	directorio = opendir("/home/gabrielo/Escritorio");
	int dir;	
	dir = mkdir("car1", 777);
	if(dir != -1){
		printf("Se creo bien\n");
	}else{
		printf("No se creo :(\n");
		exit(EXIT_FAILURE);
	}


	if(directorio != NULL){
		while((dp = readdir(directorio)) != NULL)
			printf("%s\n", dp->d_name); //dp->name
		closedir(directorio);
	}else{
		printf("No se pudo abrir el dicetorio");
		exit(EXIT_FAILURE);
	}



}
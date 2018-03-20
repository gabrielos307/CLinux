#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <dirent.h> /*manejo de carpetas y archivos*/
#include <string.h>


void listarDir(const char*, int32_t, int32_t*, int32_t*);

/*
int8_t //signed char
uint8_t //unsigned char
int16_t //signed int
uint16_t //unsigned int
int32_t //signed long int
uint32_t //unsigned long int
int64_t //signed long long int
uint64_t //unsigned long long int
*/


int32_t main(int32_t argc, char const *argv[])
{
	if(argc == 2){
		int32_t dirs = 0, archs = 0; //declaramos variables
		printf("[%s]\n", argv[1]); //Al inicio nos escibirá la ruta que hayamos indicado
		listarDir(argv[1], 1, &dirs, &archs); //
		printf("\nDirectorios: %d, Archivos: %d\n", dirs, archs); 
		return EXIT_SUCCESS;
	}else{
		printf("Error al ingresar los parametros");
		return EXIT_FAILURE;
	}

}

void listarDir(const char *rutaParcial, int32_t nivel, int32_t *d, int32_t *a){ //d de dir, a de arch
	char *ruta = (char *)calloc(, sizeof(char)); //reservamos memoria porque no sabemos cuantos caracteres ocuparemos
	DIR *carpeta; //una variable tipo DIR
	struct dirent *contenido; //Podremos acceder al contenido de la carpeta
	if(!ruta){ //si no ponemos bien la ruta
		perror("Error: "); //nos marca exactamente el error que tengamos
		return;
	}
	if(!(carpeta = opendir(rutaParcial))){ //si no se puede abrir la carpeta o directorio
		perror("Error: ");
		return;
	}
	if(!(contenido = readdir(carpeta))){ //si no se puede leer el contenido
		perror("Error: ");
		return;
	}

	do{
		if(contenido->d_type == DT_DIR){ //compara si es carpeta
				snprintf(ruta, 1023, "%s/%s", rutaParcial, contenido->d_name); //recibe la ruta, el tamaño, lo que queramos que imprima
				if(strcmp(contenido->d_name, ".") == 0 ||
					strcmp(contenido->d_name, "..") == 0)
					continue;
				printf("%*s[%s]\n", nivel*4,"", contenido->d_name); 
				(*d)++;
				listarDir(ruta, nivel+1, d, a);
		}else{
			printf("%*s[%s]\n", nivel*4, "", contenido->d_name);
			(*a)++;
		}
	}while(contenido = readdir(carpeta)); //minetras este leyendo algo
	closedir(carpeta);
	free(ruta);
}

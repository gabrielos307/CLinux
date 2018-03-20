#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *archivo;
	char caracter;
	//char cadena[50];

	archivo = fopen("archivo.txt", "r");
	if(archivo == NULL){
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	printf("El contenido del archivo es: \n");
	while(caracter != EOF){
		caracter = fgetc(archivo);
		printf("%c\n", caracter);
	}
	fclose(archivo);
	archivo = fopen("archivo.txt", "r");
	if(archivo == NULL){
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	while(!feof(archivo)){
		fgets(cadena, 50, archivo);
		printf("%s", cadena);
	}
	printf("\n");

	return 0;
}
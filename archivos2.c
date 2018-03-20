#include <stdio.h>
#include <stdlib.h>
//CONJUNTO DE BITS QUE SON ALMACENADOS EN UN DISPOSITIVO, ES IDENTIFICADO POR SU NOMBRE Y DIRECTORIO

int main(int argc, char const *argv[])
{
	FILE *archivo;

	char cadena[30];
	char leida[100];

	archivo = fopen("archivo.txt", "w+");
	printf("Agrega algo al archivo: ");
	scanf("%s", cadena);
	fputs(cadena, archivo);
	//fclose(archivo);
	//archivo = fopen("archivo.txt", "r");
	rewind(archivo);
	//fgets(leida, sizeof(leida), archivo);
	fgets(cadena, sizeof(cadena), archivo);
	fclose(archivo);
	printf("Cadena leida: %s\n", cadena);
	return 0;
}
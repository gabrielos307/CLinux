#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *archivo, *archivo2;
	char c1, c2;

	archivo = fopen("archivo.txt", "r");
	if(archivo == NULL){
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	else{
		printf("El archivo se abrio correctamente\n");
	}
	fscanf(archivo, "%c%c",&c1,&c2);
	archivo2 = fopen("copia.txt", "w");
	fprintf(archivo2, "bla bla %c %c", c1, c2);
	fclose(archivo);
	fclose(archivo2);
	return 0;
}
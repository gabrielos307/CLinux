#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	int edad;
}alumnos;
void vaciar(char cadena[]);
void copiar(char temp[], int i);
alumnos *alu;
int main(){
	char temp[50];
	char aux;
	int cont = 0, i, j;
	//alumnos *alu; //Esctructura tipo alumnos
	FILE *archivo; //Se declara el archivo
	archivo = fopen("/home/gabrielo/Escritorio/CLinux/alumnos.txt", "r"); //abrimos el archivo
	if(archivo == NULL){
		printf("NO se pudo abrir el archivo\n");
		exit(EXIT_FAILURE);
	}
	//Bloque de codigo para poder reservar tanta memoria
	while(!feof(archivo)){ //Va leer todo el archivo
		fgets(temp, 50, archivo); //Va leer todo el renglon
		cont++; //cada vez que repita el renglon que incremente
	}
	rewind(archivo);
	alu = (alumnos*)malloc(cont*sizeof(alumnos));
	if(alu == NULL){
		printf("NO se pudo reservar memoria");
		exit(EXIT_FAILURE); 
	}
	for(i = 0; !feof(archivo); i++){
		vaciar(temp);
		aux = '0';
		for(j = 0; aux != '-'; j++){
			aux = fgetc(archivo);
			if(aux != '-'){
				temp[j]=aux;
			}
		}
		copiar(temp, i);
		fgets(temp, 4, archivo);
		alu[i].edad = atoi(temp); //funcion que convierte de caracter a entero
		printf("\nNombre: %s, Edad: %i\n", alu[i].nombre,alu[i].edad);
	}
	printf("\n");
	fclose(archivo);
	return 0;

}

void vaciar(char cadena[]){
	int i;
	for(i=0;i<50;i++){
		cadena[i]= '\0';
	}
}

void copiar(char temp[], int i){
	//alumnos *alu;
	int N = strlen(temp) + 1;
	alu[i].nombre = (char*)malloc(N*sizeof(char));
	if(alu[i].nombre == NULL){
		printf("No se pudo reservar memoria");
		exit(EXIT_FAILURE);
	}
	strcpy(alu[i].nombre, temp);
}
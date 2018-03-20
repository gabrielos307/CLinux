#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//int8_t int16_t int32_t int64_t
//uint8_t uint16_t uint32_t uint64_t

//int_least8_t "16" "32" "64"
//uint_least8_t bla bla bla
//int_fast8_ ble ble ble uint_fast8_t
//intptr_t unintptr_t

//intmax_t uintmax_t

#include <stdbool.h>

bool obtenTam(char *);

int32_t main(int argc, char const *argv[])
{
	
	if(argc == 2){
		if(obtenTam(argv[1])){
			printf("Error te metimos muchos parámetro\n");
			return EXIT_FAILURE;
		}else
			return EXIT_SUCCESS;
	}else{
		printf("Nel prro\n");
		return EXIT_FAILURE;
	}
	
} 
bool obtenTam(char *archivo){
	int32_t size;
	FILE *arch = NULL;
	if(!(arch = fopen(archivo, "r")))
		return true;
	fseek(arch, 0, SEEK_END);
	size = ftell(arch);
	printf("El tamaño del archivo: %d bytes\n",size);
	if(fclose(arch))
		return true;
	else
		return false;
}
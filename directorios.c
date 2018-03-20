#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	int dir = mkdir("/home/gabrielo/Escritorio/CC", 0777);
	if(dir == 0){
		printf("Se creo el archivo\n");
	}
	else{
		printf("Hubo error\n");
	}
	/*
	int eldir = rmdir("/home/gabrielo/Escritorio/CC");
	if(eldir == 0){
		printf("Se elimino el archivo\n");
	}
	else{
		printf("Hubo error\n");
	}

	*/
}
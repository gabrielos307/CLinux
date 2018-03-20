#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	DIR *dir = opendir("/home/gabrielo/Escritorio/CC");
	if(dir != NULL){
		printf("Se abrio con exito\n");
	}
	else{
		printf("NO se abrio\n");
	}

}
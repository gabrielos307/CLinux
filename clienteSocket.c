#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
	struct sockaddr_in server;
	char ip[16];
	char enviar[1024];
	char recibir[1024];
	int fd_server, puerto;

	printf("Ingrese la IP de servidor\n");
	scanf("%s", ip);
	printf("Ingrese el puerto de conexion: \n");
	scanf("%d", &puerto);
	if((fd_server = socket(AF_INET, SOCK_STREAM,0))==-1){
		printf("ERROR: NO SE PUEDO CREAR EL SOCKET");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = inet_addr(ip);
	bzero(&(server.sin_zero),8);

	if(connect(fd_server,(struct sockaddr_in *)&server, sizeof(sockaddr_in))==-1){
		printf("ERROR: NO SE PUDO CONECTAR AL SERVIDOR\n");
		exit(-1);
	}
	recv(fd_server, recibir, 1024, 0);
	printf("%s\n",recibir );

	while(1){
		printf("Escribir mensaje\n");
		fgets(enviar, 1024, stdin);
		//equivalente a write
		send(fd_server, enviar, 1024,0);
		if(strncasecmp(enviar, "bai",3)==0) break;
		printf("Esperando respuesta del servidor\n");
		recv(fd_server, recibir, 1024, 0);
		printf("Servidor dice: %s\n",recibir);
	}
	close(fd_server);
	return 0;
}


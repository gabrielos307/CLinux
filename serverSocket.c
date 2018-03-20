/*
servidor:               cliente:

socket();			    socket();
bind();                 connect();
listen();               recv(); send();
accept();				close();
read(); write();
close();

*/

//Servidor 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

 int main(int argc, char const *argv[])
 {
 	struct sockaddr_in server;
 	struct sockaddr_in cliente;
 	int fd_cliente, fd_server, l_cliente, puertos;
 	char recibir[1024];
 	char enviar[1024];
 	printf("Ingresa puerto a la escucha: \n");
 	scanf("%d", &puertos);

 	server.sin_family = AF_INET;
 	server.sin_port = htons(puertos);
 	server.sin_addr.s_addr = INADDR_ANY;
 	bzero(&(server.sin_zero), 8);

 	if((fd_server = socket(AF_INET, SOCK_STREAM, 0))<0){
 		printf("ERROR: No se pudo crear el socket\n");
 		exit(-1);
 	}

 	if(bind(fd_server, (struct sockaddr *)&server, sizeof(struct sockaddr_in))==-1){
 		printf("ERROR: NO Se pudo\n");
 		exit(-1);
 	}

 	if(listen(fd_server, 1)==-1){
 		printf("ERROR: NO se poner en escucha\n");
 		exit(-1);
 	}

 	printf("SERVIDOR EN ESCUCHA\n");
 	l_cliente = sizeof(struct sockaddr *);
 	if((fd_cliente= accept(fd_server, (struct sockaddr *)&cliente, &l_cliente))==-1){
 		printf("ERROR: NO se pudo aceptar al cliente\n");
 		exit(-1);
 	}
 	printf("SESION INICIADA");
 	printf("CLIENTE CONECTADO\n");
 	strcpy(enviar, "CONECTADO AL SERVIDOR");
 	write(fd_cliente, enviar, 1024);
 	while(1){
 		printf("Esperando respuesta\n");
 		read(fd_cliente, recibir,1024);
 		printf("Cliente dice: %s\n",recibir );
 		printf("Escribir mensaje: \n");
 		fgets(enviar, 1024, stdin);
 		write(fd_cliente, enviar, 1024);
 		if(strcmp(enviar, "bai")==0) break;
 	}
 	printf("CONEXION TERMINADA\n");
 	close(fd_cliente);
 	close(fd_server);
 	return 0;

 }
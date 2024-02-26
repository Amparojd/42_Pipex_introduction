#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	int fd[2];//tamaño 2 para almacenar fd[0](lectura), fd[1](escritura)
	pid_t pid;
	char buffer[20];
 
	if (pipe(fd) == -1)//error
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
 
	pid = fork();//creamos un nuevo proceso hijo
	/*Después de esta llamada, tenemos dos procesos (padre e hijo)*/
	if (pid == -1)//verificamos si la llamada a fork falló
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
 
	if (pid == 0)//entramos en el proceso hijo
	{
		close(fd[0]); // cerramos extremo de lectura fd[0]
		write(fd[1], "Hello parent!", 13);
		close(fd[1]); // cerramos extremo de escritura fd[1]
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // cerramos extremo de escritua fd[1]
		read(fd[0], buffer, 20);//lee el fd[0] que ha escrito el hijo
		close(fd[0]); // cerramos extremo de lectura fd[0]
		printf("Message from child: %s\n", buffer);
		exit(EXIT_SUCCESS);
	}
}
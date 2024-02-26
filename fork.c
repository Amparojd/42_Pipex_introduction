#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
	pid_t pid;
	/*pid_t es de tipo int. Se utiliza como indicador de procesos*/
 
	pid = fork();
	/*Con fork() creamos un nuevo proceso.
	Después de llamar a fork hay 2 procesos en ejecución (padre e hijo)
	El proceso hijo es una copia exacta del proceso padre, incluyendo:
	-código
	-datos
	-estado del proceso*/
	if (pid == -1)//-1 notifica error
	{
		perror("fork");
		exit(EXIT_FAILURE);
		/*exit para finalizar el programa, 
		EXIT_FAILURE es un macro e indica un fallo al salir del 
		programa (generalmente tiene un valor de -1 o 1 dependiendo
		del sistema operativo)*/
	}
 
	if (pid == 0) //Si está en el proceso hijo, el valor devuelto debe ser 0
		printf("This is the child process. (pid: %d)\n", getpid());
	else		
		printf("This is the parent process. (pid: %d)\n", getpid());
 
	return (0);
}

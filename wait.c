#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork(); //creamos proceso hijo (ya tenemos 2 procesos)
	if (pid == -1)//error
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("I am the child process.\n");
		sleep(2);//tiempo en el que el proceso hijo terminará
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);//hace que el proceso padre espere a que el hijo termine de ejecutarse
		///una vez el hijo termine, el padre seguirá ejecutando su programa
		printf("Child process terminated after a 2s delay.\n");
	}
	return (EXIT_SUCCESS);
}

#include <unistd.h>
#include <stdio.h>

int main()
{
	char *args[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	/*execve ejecuta un programa en el espacio de memoria
	del proceso actual. En este caso, se intenta ejecutar ls
	ubicado en bin/ls*/
	printf("This line will not be executed.\n");
	/*Esta linea no se debería ejecutar, ya que hemos reemplazado 
	el programa actual por el que hemos especificado.*/
	return (0);
}
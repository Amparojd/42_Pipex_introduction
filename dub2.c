#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
	int fd; //variable para almacenar el file descriptor
 
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	//abrimos O_WRONLY (escritura) si no existe, O_CREAT (lo crea)
	//0644 ver permisos Unix
	dup2(fd, STDOUT_FILENO);
	//dup2 duplica el fd en STDOUT_FILENO (fd estandar de salida)
	//Cualquiera salida que se enviaría a la consola (STDOUT) ahora se
	//enviará al archivo "example.txt", porque lo redirecciona
	close(fd);
	//close cierra el fd original porque no se necesita, ya que hemos
	//redirigido a través de STDOUT_FILENO
	printf("This is printed in example.txt!\n");
	return (0);
}

/*Permisos UNIX
Lectura (r)
Escritura(w)
Ejecución(x)*/
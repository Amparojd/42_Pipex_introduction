#include <stdio.h>
#include <unistd.h>
 
int main()
{
	if (unlink("example.txt") == 0)//0 porque unlink ha eliminado el archivo correctamente
		printf("File successfully deleted");
	else
		printf("Error deleting file");

	return (0);
}

/*unlink se utiliza para eliminar el archivo que se especifique
en este caso sería example.txt*/
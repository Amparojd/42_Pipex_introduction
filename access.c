#include <stdio.h>
#include <unistd.h>


/*Se verifica con access que example.txt es 
accesible para lectura (R_OK)*/

int main()
{
	if (access("example.txt", R_OK) != -1) //-1 es error
		printf("I have permission\n");
	else
		printf("I don't have permission\n");
	return (0);
}
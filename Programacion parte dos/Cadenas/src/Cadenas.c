#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main(void)
{
	setbuf(stdout, NULL);
	char Nombre[500];

	getNombre("ingrese nombre y apellido= ","ingrese de nuevo",Nombre,3,500-1);

	printf("%s",Nombre);
	return 1;
}






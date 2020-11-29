#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_ALUMNOS 50

typedef struct sAlumno
{
	char nombre[50];
	int legajo;
	int estado;
	int id;

}Alumno;
int initAlumnos(Alumno arrayAlumnos[], int limite);
void mostrarStruct (Alumno *alumnos ,int cantidad);
int IngresarNombreYlegajo(Alumno alumnos[],int cantidad);
int imprimirAlumnosSeleccionado(Alumno ArrayAlumnos[], int limite,int indice);
int buscarLibre(Alumno arrayAlumnos[], int limite);
int imprimirAlumnos(Alumno ArrayAlumnos[], int limite);
int altaAlumno2(Alumno arrayAlumnos[],int limite);
int generarIdNuevo(void);
int findById (Alumno arrayAlumnos[],int limite ,int id);

int main(void) {

	setbuf(stdout, NULL);
	//int op;
	Alumno alumnos[5];


	initAlumnos(alumnos, 5);
	//IngresarNombreYlegajo(alumnos, 5);
	for(int j =0; j < 3 ; j++)
	{
		altaAlumno2(alumnos, 5);

	}
		imprimirAlumnos(alumnos, 5);
		if(findById(alumnos, 5,2)>=0)
		{
			printf ("\nEl indice es = %d",findById(alumnos, 5,2));
		}

	//imprimirAlumnosSeleccionado(alumnos, 5, 0);
	//printf("\nel lugar libre que encontro es = %d",buscarLibre(alumnos,5));
/*
 *


	do
	{
		utn_getNumero(&op, "\n1-Alta \n2-Mostrar \n1-Error", "error", 1, 3, 3);

		switch(op)
		{
		case 1:
			if(utn_getNumero(&op, "\n Indice? ", "error", 1, QTY_ALUMNOS, 3)==0)
			{
				//altaAlumnos(arrayAlumnos,QTY_ALUMNOS);
			}

			break;

		case 2:
			//imprimirAlumnos()
			break;
		}

	}
	while (1);
	{}
*/

	return 1;
}



void mostrarStruct (Alumno *alumnos ,int cantidad)
{
	int i;
	for(i=0;i<cantidad;i++)
		{
			printf("El nombre es = %s \nLegajo es = %d\n",alumnos[i].nombre , alumnos[i].legajo);
		}
}


int IngresarNombreYlegajo(Alumno alumnos[],int cantidad)
{
	int i;
	char aux[100];
	int legajo=1;
	for(i=0; i < cantidad;i++)
	{
		if (utn_getCadena(aux, 50, "ingresar nombre = ", "error, vuelva a ingresar", 5)==0)
			{
				strncpy(alumnos[i].nombre, aux, 50 );
			}

		alumnos[i].legajo = legajo;
		alumnos[i].estado = 1;
		legajo++;
	}
	return 0;
}



int altaAlumno(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(arrayAlumnos != NULL && limite >0 && indice >=0 && indice < limite )
	{
		if((utn_getNumero(&bufferAlumno.legajo, "\nlegajo?", "\nerror", 1, 9999999, 2)== 0) &&
		   (utn_getCadena(bufferAlumno.nombre , 50, "\ningresar nombre =", "Error", 5)==0 ))
		{
			arrayAlumnos[indice] = bufferAlumno;
			arrayAlumnos[indice].estado = 1;
			retorno = 0;
		}
	}

	return retorno;
}



int imprimirAlumnos(Alumno ArrayAlumnos[], int limite)
{
	int retorno = -1;
	int i;
	if(ArrayAlumnos !=NULL && limite >0)
	{
		for(i=0; i < limite ;i++)
		{
			if(ArrayAlumnos[i].estado==1)
			{
				printf("\n id = %d \nNombre= %s \nLegajo= %d ",ArrayAlumnos[i].id,ArrayAlumnos[i].nombre,ArrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}



int initAlumnos(Alumno arrayAlumnos[], int limite)
{
	int retorno =-1;
	int i;
	if (arrayAlumnos != NULL && limite > 0)
	{
		for(i=0; i < limite ;i++)
			{
				arrayAlumnos[i].estado = 0;
			}
		retorno=0;
	}

return retorno;
}



int imprimirAlumnosSeleccionado(Alumno ArrayAlumnos[], int limite,int indice)
{
	int retorno = -1;
	if(ArrayAlumnos !=NULL && limite >0 && indice > 0 )
	{
			if(ArrayAlumnos[indice].estado == 1)
			{
				printf("\nNombre= %s", ArrayAlumnos[indice].nombre );
			}else
			{
				printf("No existe el alumno o se ingreso un numero equivocado");
			}

		retorno = 0;
	}
	return retorno;
}


int buscarLibre(Alumno* arrayAlumnos, int limite)
{
	int retorno =-1;
	int i;
	if (arrayAlumnos != NULL && limite > 0)
	{
		for(i=0; i < limite ;i++)
			{
				if (arrayAlumnos[i].estado==0)
				{
					retorno = i;
					break;
				}
			}
	}


return retorno;
}


int altaAlumno2(Alumno arrayAlumnos[],int limite)
{

	int retorno = -1;
	int espacioLibre;
	Alumno bufferAlumno;

	if(buscarLibre(arrayAlumnos,limite)>=0)
	{
		espacioLibre=buscarLibre(arrayAlumnos, limite);
	}
	if(arrayAlumnos != NULL && limite >0 )
	{
		if((utn_getNumero(&bufferAlumno.legajo, "\nlegajo= ", "\nerror", 1, 9999999, 2)== 0) &&
		   (utn_getCadena(bufferAlumno.nombre , 50, "\ningresar nombre =", "Error", 5)==0 ))
		{
			arrayAlumnos[espacioLibre] = bufferAlumno;
			arrayAlumnos[espacioLibre].estado = 1;
			arrayAlumnos[espacioLibre].id= generarIdNuevo();
			retorno = 0;
		}
	}

	return retorno;
}

int generarIdNuevo(void)
{
    static int id=0;
    // es global para solo la fn puede usarla
    //guardar el ultimo que asigne (ultimo que devolvi)
    //para devolver 1+
    id = id+1;
    return id;
}


int findById (Alumno arrayAlumnos[],int limite ,int id)
{
	int retorno =-1;
	int i;
	if (arrayAlumnos != NULL && limite > 0 && id >=0)
	{
		for(i=0; i < limite ;i++)
			{
				if (arrayAlumnos[i].id==id && arrayAlumnos[i].estado==1 )
				{
					retorno=i;
					break;
				}
			}
	}
	return retorno;
}



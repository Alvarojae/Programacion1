#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "Pantalla.h"
static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int initList(Pantalla* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}



int buscarLibre(Pantalla* list, int len)
{
	int retorno =-1;
	int i;
	if (list != NULL && len > 0)
	{
		for(i=0; i < len ;i++)
			{
				if (list[i].isEmpty==1)
				{
					retorno = i;
					break;
				}
			}
	}
	return retorno;
}


/* Cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 */


static int generarIdNuevo(void)
{
	static int id=0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id+1;
	return id;
}


/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */

int add(Pantalla* list, int len)
{
	int retorno = -1;
	int espacioLibre;
	Pantalla buffer;


	if(buscarLibre(list,len)>=0)
	{
		espacioLibre=buscarLibre(list, len);

	}
	if(	list != NULL && len > 0)
	{
		if(	utn_getNombre("\nIngrese el nombre de la pantalla = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE) == 0  &&
			utn_getNombre("\nIngrese la direccion de la pantalla = ","\nError ingrese una direccion correcta",buffer.direccion,2,LONG_NOMBRE) == 0 &&
			utn_getInt("\n 1-Pantalla LCD\n 2-Pantalla Gigantes Led \nIngrese el tipo de la pantalla = ", "ingrese 1 o 2 \n", &buffer.tipoDePantalla, 2, 2, 1) ==0 &&
			utn_getFloat("\nIngrese el valor de la pantalla = ", "\nError ingrese un valor correcto (0-9999999)", &buffer.precioPublicidad, 0, 9999999, 2)== 0)
		{
			buffer.id= generarIdNuevo();
			buffer.isEmpty = FALSE;
			list[espacioLibre] = buffer;

			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Imprime los empleados  cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */

int pantalla_print(Pantalla* list, int len)
{
	int retorno = -1;
	int contador=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				pantalla_mostrar(list, i);
				contador++;
			}
		}
		if (contador ==0)
		{
			printf("\nNo hay ningun usuario para mostrar\n");
		}
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */


int pantalla_mostrar(Pantalla* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id pantalla:%d - Nombre de pantalla:%s  - direccion:%s - precio por publicidad:%.2f -" ,list[indice].id,list[indice].name,list[indice].direccion,list[indice].precioPublicidad);
			if(list[indice].tipoDePantalla==1)
			{
				printf(" el tipo de la pantalla es: LCD\n\n\n");
			}else
			{
				printf(" el tipo de la pantalla es: Led\n\n\n");
			}
			retorno = 0;
		}else
		{
			printf("No existe el usuario");
		}
	}
	return retorno;
}

int pantalla_findId(Pantalla* list,int len,int id)
{
	int retorno =-1;
	if(list != NULL && len > 0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].id== id)
				{
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

int removeNac(Pantalla* list, int len)
{

	if(list != NULL && len >= 0 )
	{
		int aux;
		char Borrar;
		int auxId;
		if(	utn_getInt("\nIngrese el id de la pantalla que desea elimnar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=pantalla_findId(list, len, aux);
			pantalla_mostrar(list,auxId);
		}
		printf("\ndesea elimnar esta pantalla = (s - n)");
		fflush(stdin);
		scanf("%c",&Borrar);
		if (Borrar=='s')
		{
			list[auxId].isEmpty=1;
			printf("\nse elimino correctamente el pais\n");
		}else
		{
			printf("\nse cancelo la eliminacion del pais\n");
		}
	}
 return -1;
}



int modificar(Pantalla list[],int len)
{
	int retorno = -1;
	Pantalla buffer;
	int aux;
	int auxId;
	char auxModificar;


	if(list != NULL && len >= 0 )
	{

		if(	utn_getInt("\nIngrese el id del usuario que desea cambiar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=pantalla_findId(list, len, aux);
			if(list[auxId].isEmpty==0)
			{
				pantalla_mostrar(list,auxId);
				buffer = list[auxId];

				printf("\ndesea cambiar esta nacionalidad = (s - n)");
				fflush(stdin);
				scanf("%c",&auxModificar);
				if (auxModificar=='s')
				{
					if(utn_getNombre("\nIngrese el nombre de la pantalla = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE) == 0)
					{
						strncpy(list[auxId].name , buffer.name,51);
					}
					if(utn_getNombre("\nIngrese la direccion de la pantalla = ","\nError ingrese una direccion correcta",buffer.direccion,2,LONG_NOMBRE) == 0)
					{
						strncpy(list[auxId].direccion , buffer.direccion,51);
					}
					if(utn_getInt("\n 1-Pantalla LCD\n 2-Pantalla Gigantes Led \nIngrese el tipo de la pantalla = ", "ingrese 1 o 2 \n", &buffer.tipoDePantalla, 2, 2, 1) ==0)
					{
						list[auxId].tipoDePantalla = buffer.tipoDePantalla;
					}
					if(utn_getFloat("\nIngrese el valor de la pantalla = ", "\nError ingrese un valor correcto (0-9999999)", &buffer.precioPublicidad, 0, 9999999, 2)== 0)
					{
						list[auxId].precioPublicidad = buffer.precioPublicidad;
					}

				}
				retorno = 1;
			}
		}

	}
	return retorno;
}


int menu()
{
    int opcion;
    printf("                ABM                      \n\n");
    printf("1-Alta de pantalla\n");
    printf("2-Modificar datos de pantalla\n");
    printf("3-Baja de pantalla\n");
    printf("4-Mostrar pantalla\n");
    printf("5-Contratar una publicidad\n");
    printf("6-mostrar publicidad\n");
    printf("10-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "contratacion.h"
static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int initList(Fantasma* list, int len)
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



int buscarLibre(Fantasma* list, int len)
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

int add(Fantasma* list, int len)
{
	int retorno = -1;
	int espacioLibre;
	Fantasma buffer;


	if(buscarLibre(list,len)>=0)
	{
		espacioLibre=buscarLibre(list, len);

	}
	if(	list != NULL && len > 0)
	{
		if(	utn_getNombre("\nIngrese pais = ","\nError ingrese un pais correcto",buffer.name,2,LONG_NOMBRE) == 0 )
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
int print(Fantasma* list, int len)
{
	int retorno = -1;
	int contador=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				mostrar(list, i);
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


int mostrar(Fantasma* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id:%d - Nombre: %s \n",list[indice].id,list[indice].name);
			retorno = 0;
		}else
		{
			printf("No existe el usuario");
		}
	}
	return retorno;
}

int findId(Fantasma* list,int len,int id)
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



int removeNac(Fantasma* list, int len)
{

	if(list != NULL && len >= 0 )
	{
		int aux;
		char Borrar;
		int auxId;
		if(	utn_getInt("\nIngrese el id del pais que desea elimnar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=findId(list, len, aux);
			mostrar(list,auxId);
		}
		printf("\ndesea elimnar esta nacionalidad = (s - n)");
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



int modificar(Fantasma list[],int len)
{
	int retorno = -1;
	Fantasma buffer;
	int aux;
	int auxId;
	char auxModificar;


	if(list != NULL && len >= 0 )
	{

		if(	utn_getInt("\nIngrese el id del usuario que desea cambiar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=findId(list, len, aux);
			if(list[auxId].isEmpty==0)
			{
				mostrar(list,auxId);
				buffer = list[auxId];

				printf("\ndesea cambiar esta nacionalidad = (s - n)");
				fflush(stdin);
				scanf("%c",&auxModificar);
				if (auxModificar=='s')
				{
						if(utn_getNombre("\nIngrese nombre = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE)==0)
						{
							strncpy(list[auxId].name , buffer.name,51);
						}

				}
				retorno = 1;
			}
		}

}
	return retorno;
}






int sortNac(Fantasma* list, int len)
{
    int retorno = -1;
    int i;
    Fantasma buffer;
    int flagSwap = 1;
    if(list != NULL && len > 0)
    {
        while(flagSwap)
        {
            flagSwap = 0;
            for (i = 0; i < (len - 1); i++)
            {
                if( strncmp(list[i].name, list[i+1].name,51) > 0 )
                {
                	buffer = list[i];
                    list[i] = list[i+1];
                    list[i+1] = buffer;
                    flagSwap = 1;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


int menu()
{
    int opcion;
    printf("                ABM                      \n\n");
    printf("1-Alta nacionalidad\n");
    printf("2-Modificar nacionalidad\n");
    printf("3-Baja nacionalidad\n");
    printf("4-Mostrar ordenados\n");
    printf("5-Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




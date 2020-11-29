#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "contratacion.h"
#include "pantalla.h"
static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int contra_initList(Contratacion* list, int len)
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



int contra_buscarLibre(Contratacion* list, int len)
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

int contra_add(Contratacion* list, int lenContra, Pantalla* listPant, int lenPant)
{
	int retorno = -1;
	int espacioLibre;
	Contratacion buffer;


	if(contra_buscarLibre(list,lenContra)>=0)
	{
		espacioLibre=contra_buscarLibre(list, lenContra);


	}
	if(	list != NULL && lenContra > 0)
	{
		if(	utn_getNombre("\nIngrese el nombre del video = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE) == 0                    &&
			utn_getCuit("\nIngrese el cuit  = ","\nError ingrese uncuit correcto",buffer.cuitCliente,2,LONG_NOMBRE) == 0 &&
			utn_getInt("\nIngrese la cantidad de dias que desea mostrar su video = ", "ingrese 1 o 2 \n", &buffer.cantidadDeDias, 2, 9999, 1) ==0   &&
			pantalla_print(listPant,lenPant)==0																									     &&
			utn_getInt("\n Ingrese la id de la pantalla que desee publicar  = ", "ingrese 1 o 2 \n", &buffer.idPantalla, 2, 9999, 1) ==0	)
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
int contra_print(Contratacion* list, int len)
{
	int retorno = -1;
	int contador=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				contra_mostrar(list, i);
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
int contra_mostrarPanYCon(Contratacion* list,int lenCon, char* cuit ,Pantalla* listPant,int lenPant)
{
	int aux;
	for(int i =0 ; i< lenCon;i++)
	{
		if( list[i].isEmpty==0 && strncmp(list[i].cuitCliente,cuit,51)==0)
		{

			contra_mostrar(list, i);
			aux=pantalla_findId(listPant, lenPant, list[i].idPantalla);

			if(aux!=-1)
			{
				pantalla_mostrar(listPant, aux);
			}else
			{
				printf("No encontro una pantalla vinculada");
			}
		}
	}

	return 1;
}











int contra_mostrar(Contratacion* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id de contratacion:%d - Nombre del video: %s - cuit = %s  - cantidad de dias = %d \n",list[indice].id,list[indice].name,list[indice].cuitCliente,list[indice].cantidadDeDias);

			retorno = 0;
		}else
		{
			printf("No existe el usuario");
		}
	}
	return retorno;
}

int contra_findId(Contratacion* list,int len,int id)
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



int contra_remove(Contratacion* list, int lenCon, Pantalla* listPant,int lenPant)
{

	if(list != NULL && lenCon >= 0 )
	{
		char aux[51];
		char Borrar;
		int auxId;
		int indiceAux;
		int auxResultado;
		if(	utn_getCuit("ingresa el cuit =", "ingresa bien el cui **-********-* ", aux, 2, 51)==0)
		{
			for(int i =0 ; i< lenCon;i++)
				{
					if( list[i].isEmpty==0 && strncmp(list[i].cuitCliente,aux,51)==0)
					{

						auxId = list[i].idPantalla;
						indiceAux=pantalla_findId(listPant, lenPant, auxId);
						pantalla_mostrar(listPant, indiceAux);
					}
				}

		utn_getInt("ingresa el id pantalla que deseas eliminar de la contratacion=", "ingresa un numero", &auxResultado, 2, 500, 0);
		pantalla_mostrar(listPant, pantalla_findId(listPant, lenPant,auxResultado));

		printf("\ndesea elimnar esta contratacion = (s - n)");
		fflush(stdin);
		scanf("%c",&Borrar);
		if (Borrar=='s')
		{
			for(int j = 0;j<lenPant ; j++)
			{
				if(list[j].idPantalla==auxResultado && strncmp(list[j].cuitCliente,aux,51)==0 )
				{
					list[j].isEmpty=1;
				}
			}

			printf("\nse elimino correctamente la contratacion\n");
		}else
		{
			printf("\nse cancelo la eliminacion de contratacion\n");
		}
	}

	}
	return -1;
}



int contra_modificar(Contratacion* list,int len, int indice)
{
	int retorno = -1;
	int auxDias;
	char auxModificar;


	if(list != NULL && len >= 0 )
	{
			if(list[indice].isEmpty==0)
			{
				contra_mostrar(list,indice);
				auxDias = list[indice].cantidadDeDias;

				printf("\ndesea cambiar esta contratacion = (s - n)");
				fflush(stdin);
				scanf("%c",&auxModificar);
				if (auxModificar=='s')
				{
						if(utn_getInt("\n Ingrese la cantidad de dias que desea mostrar su video = ", "ingrese 1 o 2 \n", &auxDias, 2, 9999, 1) ==0)
						{
							printf("La cantidad de dias se cambio a = %d",auxDias);
							list[indice].cantidadDeDias=auxDias;
						}
				}
				retorno = 1;
			}


}
	return retorno;
}








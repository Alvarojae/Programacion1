#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "publicacion.h"
static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de clientes
 * \param Cliente list[], Es el puntero al array de clientes
 * \param int len, es el len de array
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_initList(Cliente* list, int len)
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


/**
 * \brief Busca si hay espacios libres en clientes
 * \param Cliente list[], Es el puntero al array de clientes
 * \param int len, es el len de array
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_buscarLibre(Cliente* list, int len)
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
 * \brief Realiza el alta de un alumno
 * \param Cliente list[], Es el puntero al array de clientes
 * \param int len, es el len de array
 * \return (-1) Error / (0) Ok
 *
 */

int cliente_add(Cliente* list, int len)
{
	int retorno = -1;
	int espacioLibre;
	Cliente buffer;


	if(cliente_buscarLibre(list,len)>=0)
	{
		espacioLibre=cliente_buscarLibre(list, len);

	}
	if(	list != NULL && len > 0)
	{
		if(	utn_getNombre("\nIngrese el nombre = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE) == 0  &&
			utn_getNombre("\nIngrese el apellido = ","\nError ingrese una apellido correcta",buffer.lastName,2,LONG_NOMBRE) == 0 &&
			utn_getCuit("\nIngrese el cuit  = ","\nError ingrese uncuit correcto",buffer.cuit,2,LONG_NOMBRE) == 0)
		{
			buffer.idCliente= generarIdNuevo();
			buffer.isEmpty = FALSE;
			list[espacioLibre] = buffer;
			printf("Se a creado con exito el cliente\n");
			cliente_mostrar(list, espacioLibre);
			retorno = 0;
		}

	}
	return retorno;
}


/**
 * \brief Imprime los empleados  cargados
 * \param Cliente list[], Es el puntero al array de clientes
 * \param int len, es el len de array
 * \return (-1) Error / (0) Ok
 *
 */

int cliente_print(Cliente* list, int len)
{
	int retorno = -1;
	int contador=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				cliente_mostrar(list, i);
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
 * \brief muestra un usuario
 * \param Cliente* list, Es el puntero al array de clientes
 * \param int indice, se pasa el indice que el usuario quiere mostrar
 * \return (-1) Error / (0) Ok
 *
 */


int cliente_mostrar(Cliente* list,int indice)
{
	int retorno = -1;

	if(list != NULL && indice >= 0 )
	{
		if(list[indice].isEmpty==0)
		{
			printf("Id cliente:%d - Nombre:%s  - apellido:%s - cuit:%s \n" ,list[indice].idCliente,list[indice].name,list[indice].lastName,list[indice].cuit);

			retorno = 0;
		}else
		{
			printf("No existe el usuario");
		}
	}
	return retorno;
}

/**
 * \brief encuentra un usuario por id y devuelve el indice
 * \param Cliente* list, Es el puntero al array de clientes
 * \param int len, se pasa el indice que el usuario quiere mostrar
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_findId(Cliente* list,int len,int id)
{
	int retorno =-1;
	if(list != NULL && len > 0)
		{
			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].idCliente== id)
				{
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}



/**
 * \brief modifica un usario
 * \param Cliente* list, Es el puntero al array de clientes
 * \param int len, se pasa el indice que el usuario quiere mostrar
 * \return (-1) Error / (0) Ok
 *
 */

int cliente_modificar(Cliente* list,int len)
{
	int retorno = -1;
	Cliente buffer;
	int aux;
	int auxId;
	char modificar;

	if(list != NULL && len >= 0 )
	{
		cliente_print(list, len);
		if(	utn_getInt("\nIngrese el id del cliente que desea cambiar = ", "\n", &aux, 2, 9999999, 0)==0)
		{
			auxId=cliente_findId(list, len, aux);
			if(list[auxId].isEmpty==0)
			{
				cliente_mostrar(list,auxId);
				buffer = list[auxId];
				utn_getChar("\ndesea cambiar esta cliente = (s - n)?  " , "Ingrese s -n" , &modificar, 3);
				if (modificar=='s')
				{
					if(utn_getNombre("\nIngrese el nombre  = ","\nError ingrese un nombre correcto",buffer.name,2,LONG_NOMBRE) == 0 &&
					   utn_getNombre("\nIngrese el apellido = ","\nError ingrese un apellido",buffer.lastName,2,LONG_NOMBRE) == 0 &&
					   utn_getCuit("\nIngrese el cuit  = ","\nError ingrese un cuit correcta",buffer.cuit,2,LONG_NOMBRE) == 0)
					{
						list[auxId] = buffer ;
					}
				}
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief fuerza la creacion de un cliente
 * \param Cliente* list, Es el puntero al array de clientes
 * \param int len, se pasa el indice que el usuario quiere mostrar
 * \param char * nombre, se pasa el nombre
 * \param char * apellido, se pasa el apellido
 * \param ichar * cuit, se pasa el cuit
 * \return (-1) Error / (0) Ok
 *
 */

int cliente_altaForzada(Cliente * list, int len , char * nombre, char * apellido, char * cuit)
{

    int retorno = -1;
    int indice;
    if (cliente_buscarLibre(list, len) >=0)
    {
    	indice = cliente_buscarLibre(list, len);
        strncpy(list[indice].name,nombre,51);
        strncpy(list[indice].lastName,apellido,51);
        strncpy(list[indice].cuit,cuit,51);
        list[indice].idCliente = generarIdNuevo();
        list[indice].isEmpty = FALSE;
        retorno = 0;
    }
    else
    {
        printf("Error - No quedan libres");
    }
    return retorno;
}



/**
 * \brief busca si hay un usuario subido
 * \param Cliente* list, Es el puntero al array de clientes
 * \param int len, se pasa el indice que el usuario quiere mostrar
 * \return (-1) Error / (0) Ok
 *
 */
int cliente_buscarUsuarioDeAlta(Cliente * list, int len)
{
	int retorno =-1;
	int i;
	if (list != NULL && len > 0)
	{
		for(i=0; i < len ;i++)
		{
			if (list[i].isEmpty==0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}




/*


 * \ brief - Ordena el array por nombre.
 * \ param - Cliente* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ param - int order, indica el orden de los elementos. 1 en caso de ascendente y 0 en caso de descendente.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.


int cliente_sortByName(Cliente* list, int len, int order)
{
    int retorno = -1;
    int i;
    Cliente aux;
    int flagSwap = 1;
    if(list != NULL && len > 0 && (order == 0 || order== 1))
    {
        while(flagSwap)
        {
            flagSwap = 0;
            for (i = 0; i < (len - 1); i++)
            {
                if(    (order == 1 &&
                    strncmp(list[i].name, list[i+1].name,51) > 0) ||
                    (order == 0 &&
                    strncmp(list[i].name, list[i+1].name,51) < 0))
                {
                    aux = list[i];
                    list[i] = list[i+1];
                    list[i+1] = aux;
                    flagSwap = 1;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

*/

